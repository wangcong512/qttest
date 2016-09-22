#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>

class BackGround : public QWidget
{
    Q_OBJECT
public:
    explicit BackGround(QWidget *parent = 0);

    void init();
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // BACKGROUND_H
