#ifndef UIENTITY_H
#define UIENTITY_H

#include <QObject>
#include <QWidget>

#include "nodedefinitions.h"

using namespace Cascade;

class UiEntity : public QWidget
{
    Q_OBJECT

public:
    explicit UiEntity(UIElementType et, QWidget *parent = nullptr);

    virtual QString getValuesAsString() = 0;

    const UIElementType elementType;
};

#endif // UIENTITY_H
