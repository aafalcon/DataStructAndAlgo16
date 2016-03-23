#include "multiwin.h"

Multiwin::Multiwin() : QWidget(NULL)
{
  // LOAD WINDOW
  setWindowTitle("Load Window");
  layout = new QGridLayout();
  // Allocate widgets
  textPrompt = new QLabel("Enter Filename:");
  textInput = new QLineEdit();
  loadButton = new QPushButton("Load");
  quitButton = new QPushButton("Quit");
  // Add widgets to layout
  layout->addWidget(textPrompt, 0, 0, 1, 2);
  layout->addWidget(textInput, 1, 0, 1, 2);
  layout->addWidget(loadButton, 1, 2, 1, 1);
  layout->addWidget(quitButton, 3, 1, 1, 1);
  setLayout(layout);
  // Connect slots
  QObject::connect(loadButton, SIGNAL(clicked()), this, SLOT(loadButtonClicked()
  ));

  // DEBUG WINDOW
  debugLayout = new QGridLayout();
  debugWin = new QWidget;
  // Allocate widgets
  codeLines = new QListWidget();
  breakButton = new QPushButton("Breakpoint");
  contButton = new QPushButton("Continue");
  stepButton = new QPushButton("Step");
  nextButton = new QPushButton("Next");
  inspectButton = new QPushButton("Inspect");
  closeButton = new QPushButton("Close");
  // Add widgets to layout
  debugLayout->addWidget(codeLines, 0, 0, 5, 3);
  debugLayout->addWidget(breakButton, 0, 3, 1, 1);
  debugLayout->addWidget(contButton, 1, 3, 1, 1);
  debugLayout->addWidget(stepButton, 2, 3, 1, 1);
  debugLayout->addWidget(nextButton, 3, 3, 1, 1);
  debugLayout->addWidget(inspectButton, 4, 3, 1, 1);
  debugLayout->addWidget(closeButton, 5, 1, 1, 1);
  debugWin->setWindowTitle("Debugger Window");
  debugWin->setLayout(debugLayout);
  // Connect slots
  QObject::connect(inspectButton, SIGNAL(clicked()), this, SLOT(inspectButtonClicked
  ()));
  QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(closeButtonClicked
  ()));

  // VALUES WINDOW
  valueLayout = new QGridLayout();
  valueWin = new QWidget;
  // Allocate widgets
  sortPrompt = new QLabel("Sort by:");
  sortBox = new QComboBox();
  sortBox->addItem("Name (ascending)");
  sortBox->addItem("Name (descending)");
  sortBox->addItem("Value (increasing)");
  sortBox->addItem("Value (decreasing)");
  varLines = new QListWidget();
  hideButton = new QPushButton("Hide");
  updateButton = new QPushButton("Update");
  // Add widgets to layout
  valueLayout->addWidget(sortPrompt, 0, 0, 1, 1);
  valueLayout->addWidget(sortBox, 0, 1, 1, 2);
  valueLayout->addWidget(varLines, 1, 0, 3, 3);
  valueLayout->addWidget(hideButton, 1, 3, 1, 1);
  valueLayout->addWidget(updateButton, 2, 3, 1, 1);
  valueWin->setWindowTitle("Values Window");
  valueWin->setLayout(valueLayout);
  // Connect slots
  QObject::connect(hideButton, SIGNAL(clicked()), this, SLOT(hideButtonClicked
  ()));



}

Multiwin::~Multiwin() {
  delete textPrompt;
  delete textInput;
  delete loadButton;
  delete quitButton;
  delete debugWin;
  delete debugLayout;
  delete inspectButton;
  delete closeButton;
  delete valueWin;
  delete valueLayout;
  delete hideButton;
  delete layout;
}

void Multiwin::loadButtonClicked()
{
  debugWin->show();
}

void Multiwin::inspectButtonClicked()
{
  valueWin->show();
}

void Multiwin::closeButtonClicked()
{
  debugWin->hide();
}

void Multiwin::hideButtonClicked()
{
  valueWin->hide();
}