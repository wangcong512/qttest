#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>

class BackGround : public QWidget
{
    Q_OBJECT
public:
    explicit BackGround(QWidget *parent = 0);
    ~BackGround();
public:
    void init(QString mapName);
    void initTiled(QString mapName);
    void paintEvent(QPaintEvent *event);


signals:

public slots:

private:
    int m_nTiledX;
    int m_nTiledY;
};

#endif // BACKGROUND_H
