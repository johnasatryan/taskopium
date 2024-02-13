#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QList>
#include <QComboBox>
#include <QListWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void setTask();
private slots:
    void handleSubmitButton();

private:
    Ui::MainWindow *ui;
    QLineEdit* titleLineEdit;
    QLineEdit* descriptionLineEdit;
    QLineEdit* assigneLineEdit;

    QComboBox* statusComboBox;
    QDateEdit* deadlineEdit;

    QComboBox* priorityComboBox;
    QList<QString> tags;
    QDateTime creationDate;
    QDateTime lastUpdated;


    QPushButton* addButton;
    QListWidget* tasksList;

    void createTaskUi();
};

#endif // MAINWINDOW_H
