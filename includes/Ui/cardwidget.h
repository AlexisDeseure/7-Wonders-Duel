#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class CardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CardWidget(QWidget *parent = nullptr);
    void setCardInfo(const QString &name, const QString &effect);
    QString getCardName() const;

signals:
    void cardClicked();

private:
    QLabel *nameLabel;
    QLabel *effectLabel;
    QPushButton *selectButton;
};

#endif // CARDWIDGET_H
