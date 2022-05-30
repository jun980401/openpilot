#include "selfdrive/ui/qt/offroad/settings.h"

#include <cassert>
#include <cmath>
#include <string>

#include <QDebug>

#include "selfdrive/ui/qt/offroad/networking.h"

#ifdef ENABLE_MAPS
#include "selfdrive/ui/qt/maps/map_settings.h"
#endif

#include "common/params.h"
#include "common/util.h"
#include "selfdrive/hardware/hw.h"
#include "selfdrive/ui/qt/widgets/controls.h"
#include "selfdrive/ui/qt/widgets/input.h"
#include "selfdrive/ui/qt/widgets/scrollview.h"
#include "selfdrive/ui/qt/widgets/ssh_keys.h"
#include "selfdrive/ui/qt/widgets/toggle.h"
#include "selfdrive/ui/ui.h"
#include "selfdrive/ui/qt/util.h"
#include "selfdrive/ui/qt/qt_window.h"

TogglesPanel::TogglesPanel(SettingsWindow *parent) : ListWidget(parent) {
  // param, title, desc, icon
  std::vector<std::tuple<QString, QString, QString, QString>> toggles{
    {
      "OpenpilotEnabledToggle",
      "오픈파일럿 활성화",
      "어댑티브 크루즈 컨트롤 및 차선 유지 운전자 지원을 위해 오픈 파일럿 시스템을 사용하십시오. 이 기능을 사용하려면 항상 주의가 필요합니다. 차량이 꺼져 있을 때 이 설정이 적용됩니다.",
      "../assets/offroad/icon_openpilot.png",
    },
    {
      "IsLdwEnabled",
      "차선 이탈 경고 활성화",
      "50km/h(31mph) 이상으로 운전하는 동안 방향 지시등을 활성화하지 않고 차량이 차선을 넘어갈 때 본래 차선으로 돌아가도록 경고를 받습니다.",
      "../assets/offroad/icon_warning.png",
    },
    {
      "IsRHD",
      "좌측 통행 활성화",
      "오픈파일럿이 좌측 통행 규칙을 따르고 오른쪽 운전석에서 운전자 모니터링을 수행하도록 허용합니다.",
      "../assets/offroad/icon_openpilot_mirrored.png",
    },
    {
      "IsMetric",
      "미터법 사용",
      "mph 대신 km/h로 속도를 표시합니다.",
      "../assets/offroad/icon_metric.png",
    },
    {
      "RecordFront",
      "운전자 카메라 녹화 및 업로드",
      "운전자를 향한 카메라에서 데이터를 업로드하고 운전자 모니터링 알고리즘을 개선하는 데 도움을 줍니다.",
      "../assets/offroad/icon_monitoring.png",
    },
    {
      "EndToEndToggle",
      "\U0001f96c 차선 사용 비활성화(실험실) \U0001f96c",
      "이 모드에서 오픈파일럿은 차선을 무시하고 사람이 생각하는 대로 운전합니다.",
      "../assets/offroad/icon_road.png",
    },
    {
      "DisengageOnAccelerator",
      "가속 페달에서 오픈파일럿 해제",
      "활성화되면 가속 페달을 밟으면 오픈파일럿이 해제됩니다.",
      "../assets/offroad/icon_disengage_on_accelerator.svg",
    },
#ifdef ENABLE_MAPS
    {
      "NavSettingTime24h",
      "24시간 형식으로 ETA 표시",
      "오전/오후 대신 24시간 형식 사용",
      "../assets/offroad/icon_metric.png",
    },
#endif

  };

  Params params;

  if (params.getBool("DisableRadar_Allow")) {
    toggles.push_back({
      "DisableRadar",
      "openpilot Longitudinal Control",
      "openpilot will disable the car's radar and will take over control of gas and brakes. Warning: this disables AEB!",
      "../assets/offroad/icon_speed_limit.png",
    });
  }

  for (auto &[param, title, desc, icon] : toggles) {
    auto toggle = new ParamControl(param, title, desc, icon, this);
    bool locked = params.getBool((param + "Lock").toStdString());
    toggle->setEnabled(!locked);
    if (!locked) {
      connect(uiState(), &UIState::offroadTransition, toggle, &ParamControl::setEnabled);
    }
    addItem(toggle);
  }
}

DevicePanel::DevicePanel(SettingsWindow *parent) : ListWidget(parent) {
  setSpacing(50);
  addItem(new LabelControl("동글 ID", getDongleId().value_or("N/A")));
  addItem(new LabelControl("시리얼 넘버", params.get("HardwareSerial").c_str()));

  // offroad-only buttons

  auto dcamBtn = new ButtonControl("운전자 카메라", "미리보기",
                                   "최상의 운전자 모니터링 경험을 위해 장치 장착 위치를 최적화하는 데 도움이 되도록 운전자를 향한 카메라를 미리 봅니다. (차량 시동은 꺼져있어야 함)");
  connect(dcamBtn, &ButtonControl::clicked, [=]() { emit showDriverView(); });
  addItem(dcamBtn);

  auto resetCalibBtn = new ButtonControl("보정 재설정", "재설정", " ");
  connect(resetCalibBtn, &ButtonControl::showDescription, this, &DevicePanel::updateCalibDescription);
  connect(resetCalibBtn, &ButtonControl::clicked, [&]() {
    if (ConfirmationDialog::confirm("보정 재설정을 하시겠습니까?", this)) {
      params.remove("CalibrationParams");
    }
  });
  addItem(resetCalibBtn);

  if (!params.getBool("Passive")) {
    auto retrainingBtn = new ButtonControl("튜토리얼 진행", "시작", "openpilot의 규칙, 기능 및 제한 사항 검토");
    connect(retrainingBtn, &ButtonControl::clicked, [=]() {
      if (ConfirmationDialog::confirm("튜토리얼을 진행하시겠습니까?", this)) {
        emit reviewTrainingGuide();
      }
    });
    addItem(retrainingBtn);
  }

  if (Hardware::TICI()) {
    auto regulatoryBtn = new ButtonControl("Regulatory", "VIEW", "");
    connect(regulatoryBtn, &ButtonControl::clicked, [=]() {
      const std::string txt = util::read_file("../assets/offroad/fcc.html");
      RichTextDialog::alert(QString::fromStdString(txt), this);
    });
    addItem(regulatoryBtn);
  }

  QObject::connect(uiState(), &UIState::offroadTransition, [=](bool offroad) {
    for (auto btn : findChildren<ButtonControl *>()) {
      btn->setEnabled(offroad);
    }
  });

  // power buttons
  QHBoxLayout *power_layout = new QHBoxLayout();
  power_layout->setSpacing(30);

  QPushButton *reboot_btn = new QPushButton("재시작");
  reboot_btn->setObjectName("reboot_btn");
  power_layout->addWidget(reboot_btn);
  QObject::connect(reboot_btn, &QPushButton::clicked, this, &DevicePanel::reboot);

  QPushButton *poweroff_btn = new QPushButton("전원 종료");
  poweroff_btn->setObjectName("poweroff_btn");
  power_layout->addWidget(poweroff_btn);
  QObject::connect(poweroff_btn, &QPushButton::clicked, this, &DevicePanel::poweroff);

  if (Hardware::TICI()) {
    connect(uiState(), &UIState::offroadTransition, poweroff_btn, &QPushButton::setVisible);
  }

  setStyleSheet(R"(
    #reboot_btn { height: 120px; border-radius: 15px; background-color: #393939; }
    #reboot_btn:pressed { background-color: #4a4a4a; }
    #poweroff_btn { height: 120px; border-radius: 15px; background-color: #E22C2C; }
    #poweroff_btn:pressed { background-color: #FF2424; }
  )");
  addItem(power_layout);
}

void DevicePanel::updateCalibDescription() {
  QString desc =
      "openpilot은 장치를 왼쪽 또는 오른쪽으로 4° 이내, 위쪽으로 5° 또는 아래쪽으로 8° 이내에 "
      "장착해야 합니다. openpilot은 계속해서 교정 중이므로 재설정이 거의 필요하지 않습니다.";
  std::string calib_bytes = Params().get("CalibrationParams");
  if (!calib_bytes.empty()) {
    try {
      AlignedBuffer aligned_buf;
      capnp::FlatArrayMessageReader cmsg(aligned_buf.align(calib_bytes.data(), calib_bytes.size()));
      auto calib = cmsg.getRoot<cereal::Event>().getLiveCalibration();
      if (calib.getCalStatus() != 0) {
        double pitch = calib.getRpyCalib()[1] * (180 / M_PI);
        double yaw = calib.getRpyCalib()[2] * (180 / M_PI);
        desc += QString(" Your device is pointed %1° %2 and %3° %4.")
                    .arg(QString::number(std::abs(pitch), 'g', 1), pitch > 0 ? "down" : "up",
                         QString::number(std::abs(yaw), 'g', 1), yaw > 0 ? "left" : "right");
      }
    } catch (kj::Exception) {
      qInfo() << "invalid CalibrationParams";
    }
  }
  qobject_cast<ButtonControl *>(sender())->setDescription(desc);
}

void DevicePanel::reboot() {
  if (!uiState()->engaged()) {
    if (ConfirmationDialog::confirm("재시작 하시겠습니까?", this)) {
      // Check engaged again in case it changed while the dialog was open
      if (!uiState()->engaged()) {
        Params().putBool("DoReboot", true);
      }
    }
  } else {
    ConfirmationDialog::alert("재시작 하려면 종료", this);
  }
}

void DevicePanel::poweroff() {
  if (!uiState()->engaged()) {
    if (ConfirmationDialog::confirm("전원을 끄시겠습니까?", this)) {
      // Check engaged again in case it changed while the dialog was open
      if (!uiState()->engaged()) {
        Params().putBool("DoShutdown", true);
      }
    }
  } else {
    ConfirmationDialog::alert("전원을 끄려면 해제", this);
  }
}

SoftwarePanel::SoftwarePanel(QWidget* parent) : ListWidget(parent) {
  gitBranchLbl = new LabelControl("Git Branch");
  gitCommitLbl = new LabelControl("Git Commit");
  osVersionLbl = new LabelControl("OS 버전");
  versionLbl = new LabelControl("버전", "", QString::fromStdString(params.get("ReleaseNotes")).trimmed());
  lastUpdateLbl = new LabelControl("마지막 업데이트 확인", "", "마지막으로 오픈파일럿이 업데이트를 성공적으로 확인했습니다. 업데이트는 차량이 꺼져 있는 동안에만 진행됩니다.");
  updateBtn = new ButtonControl("업데이트 확인", "");
  connect(updateBtn, &ButtonControl::clicked, [=]() {
    if (params.getBool("IsOffroad")) {
      fs_watch->addPath(QString::fromStdString(params.getParamPath("LastUpdateTime")));
      fs_watch->addPath(QString::fromStdString(params.getParamPath("UpdateFailedCount")));
      updateBtn->setText("확인 중");
      updateBtn->setEnabled(false);
    }
    std::system("pkill -1 -f selfdrive.updated");
  });


  auto uninstallBtn = new ButtonControl(getBrand() + " 제거", "제거");
  connect(uninstallBtn, &ButtonControl::clicked, [&]() {
    if (ConfirmationDialog::confirm("제거하시겠습니까?", this)) {
      params.putBool("DoUninstall", true);
    }
  });
  connect(uiState(), &UIState::offroadTransition, uninstallBtn, &QPushButton::setEnabled);

  QWidget *widgets[] = {versionLbl, lastUpdateLbl, updateBtn, gitBranchLbl, gitCommitLbl, osVersionLbl, uninstallBtn};
  for (QWidget* w : widgets) {
    addItem(w);
  }

  fs_watch = new QFileSystemWatcher(this);
  QObject::connect(fs_watch, &QFileSystemWatcher::fileChanged, [=](const QString path) {
    if (path.contains("UpdateFailedCount") && std::atoi(params.get("UpdateFailedCount").c_str()) > 0) {
      lastUpdateLbl->setText("업데이트를 가져오지 못했습니다.");
      updateBtn->setText("CHECK");
      updateBtn->setEnabled(true);
    } else if (path.contains("LastUpdateTime")) {
      updateLabels();
    }
  });
}

void SoftwarePanel::showEvent(QShowEvent *event) {
  updateLabels();
}

void SoftwarePanel::updateLabels() {
  QString lastUpdate = "";
  auto tm = params.get("LastUpdateTime");
  if (!tm.empty()) {
    lastUpdate = timeAgo(QDateTime::fromString(QString::fromStdString(tm + "Z"), Qt::ISODate));
  }

  versionLbl->setText(getBrandVersion());
  lastUpdateLbl->setText(lastUpdate);
  updateBtn->setText("CHECK");
  updateBtn->setEnabled(true);
  gitBranchLbl->setText(QString::fromStdString(params.get("GitBranch")));
  gitCommitLbl->setText(QString::fromStdString(params.get("GitCommit")).left(10));
  osVersionLbl->setText(QString::fromStdString(Hardware::get_os_version()).trimmed());
}

QWidget *network_panel(QWidget *parent) {
  return new Networking(parent);
}

void SettingsWindow::showEvent(QShowEvent *event) {
  panel_widget->setCurrentIndex(0);
  nav_btns->buttons()[0]->setChecked(true);
}

SettingsWindow::SettingsWindow(QWidget *parent) : QFrame(parent) {

  // setup two main layouts
  sidebar_widget = new QWidget;
  QVBoxLayout *sidebar_layout = new QVBoxLayout(sidebar_widget);
  sidebar_layout->setMargin(0);
  panel_widget = new QStackedWidget();
  panel_widget->setStyleSheet(R"(
    border-radius: 30px;
    background-color: #292929;
  )");

  // close button
  QPushButton *close_btn = new QPushButton("×");
  close_btn->setStyleSheet(R"(
    QPushButton {
      font-size: 140px;
      padding-bottom: 20px;
      font-weight: bold;
      border 1px grey solid;
      border-radius: 100px;
      background-color: #292929;
      font-weight: 400;
    }
    QPushButton:pressed {
      background-color: #3B3B3B;
    }
  )");
  close_btn->setFixedSize(200, 200);
  sidebar_layout->addSpacing(45);
  sidebar_layout->addWidget(close_btn, 0, Qt::AlignCenter);
  QObject::connect(close_btn, &QPushButton::clicked, this, &SettingsWindow::closeSettings);

  // setup panels
  DevicePanel *device = new DevicePanel(this);
  QObject::connect(device, &DevicePanel::reviewTrainingGuide, this, &SettingsWindow::reviewTrainingGuide);
  QObject::connect(device, &DevicePanel::showDriverView, this, &SettingsWindow::showDriverView);

  QList<QPair<QString, QWidget *>> panels = {
    {"장치", device},
    {"네트워크", network_panel(this)},
    {"고급 설정", new TogglesPanel(this)},
    {"소프트웨어", new SoftwarePanel(this)},
  };

#ifdef ENABLE_MAPS
  auto map_panel = new MapPanel(this);
  panels.push_back({"네비게이션", map_panel});
  QObject::connect(map_panel, &MapPanel::closeSettings, this, &SettingsWindow::closeSettings);
#endif

  const int padding = panels.size() > 3 ? 25 : 35;

  nav_btns = new QButtonGroup(this);
  for (auto &[name, panel] : panels) {
    QPushButton *btn = new QPushButton(name);
    btn->setCheckable(true);
    btn->setChecked(nav_btns->buttons().size() == 0);
    btn->setStyleSheet(QString(R"(
      QPushButton {
        color: grey;
        border: none;
        background: none;
        font-size: 65px;
        font-weight: 500;
        padding-top: %1px;
        padding-bottom: %1px;
      }
      QPushButton:checked {
        color: white;
      }
      QPushButton:pressed {
        color: #ADADAD;
      }
    )").arg(padding));

    nav_btns->addButton(btn);
    sidebar_layout->addWidget(btn, 0, Qt::AlignRight);

    const int lr_margin = name != "Network" ? 50 : 0;  // Network panel handles its own margins
    panel->setContentsMargins(lr_margin, 25, lr_margin, 25);

    ScrollView *panel_frame = new ScrollView(panel, this);
    panel_widget->addWidget(panel_frame);

    QObject::connect(btn, &QPushButton::clicked, [=, w = panel_frame]() {
      btn->setChecked(true);
      panel_widget->setCurrentWidget(w);
    });
  }
  sidebar_layout->setContentsMargins(50, 50, 100, 50);

  // main settings layout, sidebar + main panel
  QHBoxLayout *main_layout = new QHBoxLayout(this);

  sidebar_widget->setFixedWidth(500);
  main_layout->addWidget(sidebar_widget);
  main_layout->addWidget(panel_widget);

  setStyleSheet(R"(
    * {
      color: white;
      font-size: 50px;
    }
    SettingsWindow {
      background-color: black;
    }
  )");
}
