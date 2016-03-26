#ifndef MULTIWIN_H
#define MULTIWIN_H
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QComboBox>

#include <string>
#include <vector>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <iostream>

#include "Facile.h"

class Multiwin : public QWidget
{
  Q_OBJECT
public:
  Multiwin();
  ~Multiwin();
public slots:
  void loadButtonClicked();
  void inspectButtonClicked();
  void closeButtonClicked();
  void hideButtonClicked();
  void quitButtonClicked();
  void quitButton2Clicked();
  void breakButtonClicked();
  void contButtonClicked();
  void stepButtonClicked();
  void updateButtonClicked();
private:
  QGridLayout* loadLayout;
  QLabel* textPrompt;
  QLineEdit* textInput;
  QPushButton* loadButton;
  QPushButton* quitButton;

  QWidget* debugWin;
  QGridLayout* debugLayout;
  QListWidget* codeLines;
  QPushButton* breakButton;
  QPushButton* contButton;
  QPushButton* stepButton;
  QPushButton* nextButton;
  QPushButton* inspectButton;
  QPushButton* quitButton2;

  QWidget* valueWin;
  QGridLayout* valueLayout;
  QLabel* sortPrompt;
  QListWidget* varLines;
  QPushButton* hideButton;
  QPushButton* updateButton;
  QComboBox* sortBox;

  Facile* facile;
};
#endif