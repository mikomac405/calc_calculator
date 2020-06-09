#include "mainwindows.h"
#include "ui_mainwindows.h"
#include "food.cpp"


MainWindows::MainWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindows)
{
    ui->setupUi(this);
}

MainWindows::~MainWindows()
{
    delete ui;
}

void MainWindows::on_pushButton_clicked()
{
    QString sex = ui->sex->currentText();
    int W = ui->weight->value();
    int H = ui->height->value();
    int A = ui->age->value();
    double max;
    int aboutMax;

    if(sex == "Mężczyzna"){
        max = 66.47 + (13.7*W) + (5*H) - (6.76*A);
        aboutMax = max;
        ui->label_11->setNum(aboutMax);
    }
    else{
        max = 655.1 + (9.567*W) + (1.85*H) - (4.68*A);
        aboutMax = max;
        ui->label_11->setNum(aboutMax);
    }
}


void MainWindows::on_foodCategory_currentTextChanged(const QString &arg1)
{
    ui->foodList->clear();
    if(arg1 == "Fastfood"){
        ui->foodList->addItems(FastFood);
    }
    else if(arg1 == "Zupy"){
        ui->foodList->addItems(Zupy);
    }
    else if(arg1 == "Alkohol"){
        ui->foodList->addItems(Alkohol);
    }
    else if(arg1 == "Pieczywo, kasze, makarony, zboża"){
        ui->foodList->addItems(PieczywoIZboza);
    }
    else if(arg1 == "Mięso i wędliny"){
        ui->foodList->addItems(Mieso);
    }
    else if(arg1 == "Napoje"){
        ui->foodList->addItems(Napoje);
    }
    else if(arg1 == "Nabiał"){
        ui->foodList->addItems(Nabial);
    }
    else if(arg1 == "Owoce"){
        ui->foodList->addItems(Owoce);
    }
    else if(arg1 == "Produkty gotowe"){
        ui->foodList->addItems(ProduktyGotowe);
    }
    else if(arg1 == "Ryby i owoce morza"){
        ui->foodList->addItems(RybyIOwoceMorza);
    }
    else if(arg1 == "Słodycze"){
        ui->foodList->addItems(Slodycze);
    }

}

void MainWindows::add_current_item()
{
    QListWidgetItem *selItem = ui->foodList->currentItem()->clone();
    ui->eatenList->addItem(selItem);
}

void MainWindows::incProgress()
{
    QListWidgetItem *selItem = ui->foodList->currentItem()->clone();
    QString text = selItem->text();
    int cut;
    for(int i = 0; i < text.size(); i++)
    {
        if(text[i] == '/'){ cut = i+1; }
    }
    text.remove(0,cut);
    text.chop(5);
    int addVal = text.toInt();
    int curVal = ui->label_10->text().toInt();
    curVal+=addVal;
    ui->label_10->setNum(curVal);
    if(curVal>ui->label_11->text().toInt()){ui->label_10->setStyleSheet("font: 75 15pt 'MS Shell Dlg 2';\ncolor: rgb(255, 000, 000);");}
}

void MainWindows::decProgress()
{
    QListWidgetItem *selItem = ui->eatenList->currentItem()->clone();
    QString text = selItem->text();
    int cut;
    for(int i = 0; i < text.size(); i++)
    {
        if(text[i] == '/'){ cut = i+1; }
    }
    text.remove(0,cut);
    text.chop(5);
    int addVal = text.toInt();
    int curVal = ui->label_10->text().toInt();
    curVal-=addVal;
    ui->label_10->setNum(curVal);
    if(curVal<=ui->label_11->text().toInt()){ui->label_10->setStyleSheet("font: 75 15pt 'MS Shell Dlg 2';\ncolor: rgb(255, 255, 255);");}
}


void MainWindows::on_addMeal_clicked()
{
    if(ui->foodList->selectedItems().size() != 0)
    {
    int n = ui->amount->value();
    for(int i = 0; i < n; i++)
    {
        incProgress();
        add_current_item();
    }
    }

}

void MainWindows::on_removeMeal_clicked()
{
    if(ui->eatenList->selectedItems().size() != 0)
    {
    decProgress();
    QListWidgetItem *remItem = ui->eatenList->currentItem();
    int row = ui->eatenList->row(remItem);
    ui->eatenList->takeItem(row);
    }
}

void MainWindows::on_lineEdit_textChanged(const QString &arg1)
{
    int n = ui->foodList->count();
    if(n > 0){
        for(int i = 0; i < n; i++){
            if (ui->foodList->item(i)->text().contains(arg1))
            {
                QListWidgetItem *foundItem = ui->foodList->item(i);
                ui->foodList->setCurrentItem(foundItem);
                ui->foodList->scrollToItem(foundItem);
            }
        }
    }
}
