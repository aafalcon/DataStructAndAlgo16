#include "multiwin.h"

using namespace std;

Multiwin::Multiwin() : QWidget(NULL)
{
  // LOAD WINDOW
  loadLayout = new QGridLayout();
  // Allocate widgets
  textPrompt = new QLabel("Enter Filename:");
  textInput = new QLineEdit();
  loadButton = new QPushButton("Load");
  quitButton = new QPushButton("Quit");
  // Add widgets to layout
  loadLayout->addWidget(textPrompt, 0, 0, 1, 2);
  loadLayout->addWidget(textInput, 1, 0, 1, 2);
  loadLayout->addWidget(loadButton, 1, 2, 1, 1);
  loadLayout->addWidget(quitButton, 3, 1, 1, 1);
  setWindowTitle("Load Window");
  setLayout(loadLayout);
  // Connect slots
  QObject::connect(loadButton, SIGNAL(clicked()), this, SLOT(loadButtonClicked()
  ));
  QObject::connect(textInput, SIGNAL(returnPressed()), this, SLOT(loadButtonClicked()
  ));
  QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(quitButtonClicked
  ()));

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
  quitButton2 = new QPushButton("Quit");
  // Add widgets to layout
  debugLayout->addWidget(codeLines, 0, 0, 5, 3);
  debugLayout->addWidget(breakButton, 0, 3, 1, 1);
  debugLayout->addWidget(contButton, 1, 3, 1, 1);
  debugLayout->addWidget(stepButton, 2, 3, 1, 1);
  debugLayout->addWidget(nextButton, 3, 3, 1, 1);
  debugLayout->addWidget(inspectButton, 4, 3, 1, 1);
  debugLayout->addWidget(quitButton2, 5, 1, 1, 1);
  debugWin->setWindowTitle("Debugger Window");
  debugWin->setLayout(debugLayout);
  // Connect slots
  QObject::connect(breakButton, SIGNAL(clicked()), this, SLOT(breakButtonClicked
  ()));
  QObject::connect(contButton, SIGNAL(clicked()), this, SLOT(contButtonClicked
  ()));
  QObject::connect(stepButton, SIGNAL(clicked()), this, SLOT(stepButtonClicked
  ()));
  QObject::connect(inspectButton, SIGNAL(clicked()), this, SLOT(inspectButtonClicked
  ()));
  QObject::connect(quitButton2, SIGNAL(clicked()), this, SLOT(quitButton2Clicked
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
  QObject::connect(updateButton, SIGNAL(clicked()), this, SLOT(updateButtonClicked
  ()));
  QObject::connect(hideButton, SIGNAL(clicked()), this, SLOT(hideButtonClicked
  ()));
}

Multiwin::~Multiwin() {
  // LOAD Window
  delete loadLayout;
  delete textPrompt;
  delete textInput;
  delete loadButton;
  delete quitButton;
  // DEBUG Window
  delete debugWin;
  delete debugLayout;
  delete codeLines;
  delete breakButton;
  delete contButton;
  delete stepButton;
  delete nextButton;
  delete inspectButton;
  delete quitButton2;
  // VALUES Window
  delete valueWin;
  delete valueLayout;
  delete sortBox;
  delete varLines;
  delete hideButton;
  delete updateButton;

  delete facile;
}

void Multiwin::loadButtonClicked()
{
  codeLines->clear();
  // Do nothing if user left at least one input blank
  if(textInput->text().isEmpty())
  {
    return;
  }

  string filename;
  filename = textInput->text().toStdString();
  ifstream infile(filename.c_str());
  if (!infile)
  {
    cout << "Cannot open " << filename << "!" << endl;
    return;
  }

  facile = new Facile(infile);
  
  int size = facile->getNumLines();

  for (int i=0; i<size; ++i) {
    codeLines->addItem(QString::fromStdString(facile->getLine(i)));
  }

  // Clear the form inputs
  textInput->setText("");
  this->hide();
  debugWin->show();
}

void Multiwin::quitButtonClicked()
{
  exit(EXIT_SUCCESS);
}

void Multiwin::breakButtonClicked()
{
  // either adds a new breakpoint or removes existing breakpoint
  facile->addBreakpoint(codeLines->currentRow());
  if (facile->breakExist(codeLines->currentRow()))
  {
    // if breakpoint added make color red
    codeLines->item(codeLines->currentRow())->setBackground(Qt::red);
  }
  else
  {
    // if breakpoint removed change back to white
    codeLines->item(codeLines->currentRow())->setBackground(Qt::white);
  }
  
}

void Multiwin::contButtonClicked()
{
  facile->executeProgram(cout);
}

void Multiwin::stepButtonClicked()
{
  facile->executeLine(cout);
}

void Multiwin::inspectButtonClicked()
{
  varLines->clear();
  int size = facile->getNumVar();
  for (int i=0; i<size; ++i) {
    varLines->addItem(QString::fromStdString(facile->printIndex(i)));
  }
  valueWin->show();
}

void Multiwin::quitButton2Clicked()
{
  exit(EXIT_SUCCESS);
}

void Multiwin::closeButtonClicked()
{
  debugWin->hide();
}

void Multiwin::updateButtonClicked()
{
  varLines->clear();
  int size = facile->getNumVar();
  for (int i=0; i<size; ++i) {
    varLines->addItem(QString::fromStdString(facile->printIndex(i)));
  }
}

void Multiwin::hideButtonClicked()
{
  valueWin->hide();
}