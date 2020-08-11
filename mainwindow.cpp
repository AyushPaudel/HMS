#include "mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hotel Management System");
    homeScreen();  // TO Display Home Screen

}

// Definition of homescreen()

void MainWindow::homeScreen(){

    // Creating a main widget
    QWidget *window = new QWidget(this);
    setCentralWidget(window);

    window->setStyleSheet("*{background-image:url(\"/home/aadarsha/Desktop/bg.jpg\");}"); // Giving Background Image


    QVBoxLayout *layout = new QVBoxLayout(); // Defining Box Layout

    // Displays Welcome Text at the center
    QLabel *label = new QLabel(window);
    label->setText("Welcome!");
    QFont banner("Helvetica",30,QFont::Bold);
    label->setFont(banner);
    label->setAlignment(Qt::AlignHCenter| Qt::AlignVCenter);

    // Go to Dashboard Button Bottom

    QPushButton *beginButton = new QPushButton("Go To Dashboard");
    beginButton->setStyleSheet("*{background:green;height:30px;}");
    beginButton->adjustSize();
    connect(beginButton,SIGNAL(clicked()),this,SLOT(dashboard())); // Triggers loginScreen() method when button is clicked
                                                                     // Navigates to the loginScreen.

    //Exit App Button Bottom
    QPushButton *exitButton = new QPushButton("Exit App");
    exitButton->setStyleSheet("*{background:red;height:30px;}");
    exitButton->adjustSize();
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close())); //Exits the App


    // Adding all widgets to layout
    layout->addWidget(label);
    layout->addWidget(beginButton);
    layout->addWidget(exitButton);

    window->setLayout(layout); // Setting previously defined BoxLayout to main widget

}

MainWindow::~MainWindow()
{

}
