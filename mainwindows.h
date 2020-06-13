#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QMainWindow>
#include <QMap>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindows; }
QT_END_NAMESPACE

class MainWindows : public QMainWindow
{
    Q_OBJECT

public:
    MainWindows(QWidget *parent = nullptr);
    ~MainWindows();

private slots:
    void on_pushButton_clicked();

    void on_foodCategory_currentTextChanged(const QString &arg1);

    void on_addMeal_clicked();

    void add_current_item();

    void on_removeMeal_clicked();

    void incProgress();

    void decProgress();
;

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindows *ui;
};
#endif // MAINWINDOWS_H
