#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    createTaskUi();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createTaskUi() {
    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    centralWidget->setStyleSheet(
        "QPushButton {"
        "   background-color: #0078d7;"
        "   color: white;"
        "   padding: 5px;"
        "   border-radius: 5px;"
        "   font-weight: bold;"
        "}"
        );
    // Create components.

    titleLineEdit = new QLineEdit;
    descriptionLineEdit = new QLineEdit;

    assigneLineEdit = new QLineEdit;
    statusComboBox = new QComboBox(this);
    priorityComboBox = new QComboBox(this);
    addButton = new QPushButton("Add Task", this);

    // Optionally, set placeholders.
    titleLineEdit->setPlaceholderText("Title");
    descriptionLineEdit->setPlaceholderText("Description");
    assigneLineEdit->setPlaceholderText("Assigne");

    // Set a consistent width for input fields and combo boxes.
    int inputFieldWidth = 200;
    titleLineEdit->setMinimumWidth(inputFieldWidth);
    descriptionLineEdit->setMinimumWidth(inputFieldWidth);
    assigneLineEdit->setMinimumWidth(inputFieldWidth);
    statusComboBox->setMinimumWidth(inputFieldWidth);
    priorityComboBox->setMinimumWidth(inputFieldWidth);


    // Add items to combo boxes.
    statusComboBox->addItems({"Done", "In Progress", "Backlog", "Failed"});
    priorityComboBox->addItems({"Low", "Medium", "High"});

    // Create labels.
    QLabel *titleLabel = new QLabel("Title:");
    QLabel *descriptionLabel = new QLabel("Description:");
    QLabel *assigneLabel = new QLabel("Assigne:");
    QLabel *statusLabel = new QLabel("Status:");
    QLabel *priorityLabel = new QLabel("Priority:");


    // Initialize the QDateEdit for the deadline.
    deadlineEdit = new QDateEdit(QDate::currentDate(), this);
    deadlineEdit->setDisplayFormat("yyyy-MM-dd");
    deadlineEdit->setCalendarPopup(true);
    deadlineEdit->setAccelerated(false);
    deadlineEdit->setMinimumWidth(inputFieldWidth);
    QLabel *deadlineLabel = new QLabel("Deadline:");
    // Create a frame to hold the form elements.
    QFrame *formFrame = new QFrame(this);
    formFrame->setFrameShape(QFrame::StyledPanel);
    formFrame->setStyleSheet("background-color: #ffffff;"
                             "border: 1px solid #c0c0c0;"
                             "border-radius: 10px;"
                             "padding: 15px;");



    // Create the form layout and add your widgets.
    QFormLayout *formLayout = new QFormLayout(formFrame);
    formLayout->setContentsMargins(10, 10, 10, 10);
    formLayout->setSpacing(10);
    formLayout->addRow(titleLabel, titleLineEdit);
    formLayout->addRow(descriptionLabel, descriptionLineEdit);
    formLayout->addRow(assigneLabel, assigneLineEdit);
    formLayout->addRow(statusLabel, statusComboBox);
    formLayout->addRow(priorityLabel, priorityComboBox);
    formLayout->addRow(deadlineLabel, deadlineEdit);


    statusComboBox->setStyleSheet(
        "QComboBox {"
        "   combobox-popup: 0;"
        "}"
        "QComboBox::item:selected {"
        "   background-color: #5A5A5A;"
        "   color: white;"
        "}"
        );
    priorityComboBox->setStyleSheet(statusComboBox->styleSheet());
    // Button layout.
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(addButton);
    buttonLayout->addStretch(1);
    // Main layout for the central widget.
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(formFrame, 0, Qt::AlignCenter);
    mainLayout->addLayout(buttonLayout);


    tasksList = new QListWidget(this); // Initialize the QListWidget
    mainLayout->addWidget(formFrame, 0, Qt::AlignCenter);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(tasksList);
    // Connect the addButton click signal to the appropriate slot.
    connect(addButton, &QPushButton::clicked, this, &MainWindow::handleSubmitButton);
}


void MainWindow::handleSubmitButton() {
    // Gather task details
    QString title = titleLineEdit->text();
    QString description = descriptionLineEdit->text();
    QString status = statusComboBox->currentText();
    QString priority = priorityComboBox->currentText();
    QString deadline = deadlineEdit->date().toString("yyyy-MM-dd");

    // Create a string to represent the task
    QString taskDetails = QString("Title: %1, Description: %2, Status: %3, Priority: %4, Deadline: %5")
                              .arg(title, description, status, priority, deadline);


    // Add the task details to the list
    tasksList->addItem(taskDetails);

    // Optional: Clear the input fields after adding the task
    titleLineEdit->clear();
    descriptionLineEdit->clear();
    assigneLineEdit->clear();
    statusComboBox->clearEditText();
    priorityComboBox->clearEditText();
    deadlineEdit->setDate(QDate::currentDate());
    // You may also reset the statusComboBox, priorityComboBox, and deadlineEdit if needed
}
