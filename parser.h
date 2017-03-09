#ifndef PARSER_H
#define PARSER_H

#include <QObject>

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = 0);
    bool permissionToStart = true;
signals:

public slots:
};

#endif // PARSER_H
