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
private:
  QGridLayout* layout;
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
  QPushButton* closeButton;

  QWidget* valueWin;
  QGridLayout* valueLayout;
  QLabel* sortPrompt;
  QListWidget* varLines;
  QPushButton* hideButton;
  QPushButton* updateButton;
  QComboBox* sortBox;
};
#endif