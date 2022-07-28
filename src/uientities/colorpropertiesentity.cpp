/*
 *  Cascade Image Editor
 *
 *  Copyright (C) 2022 Till Dechent and contributors
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "colorpropertiesentity.h"
#include "ui_colorpropertiesentity.h"

namespace Cascade {

ColorPropertiesEntity::ColorPropertiesEntity(UIElementType et, QWidget *parent) :
    UiEntity(et, parent),
    mUi(new Ui::ColorPropertiesEntity)
{
    mUi->setupUi(this);

    // Master
    CsSliderBoxEntity* item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Saturation");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->masterLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Contrast");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->masterLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Gamma");
    item->setMinMaxStepValue(0.0, 5.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->masterLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Gain");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->masterLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Lift");
    item->setMinMaxStepValue(-1.0, 1.0, 0.01, 0.0);
    mUiItems.push_back(item);
    mUi->masterLayout->addWidget(item);

    // Shadows
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Saturation");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->shadowsLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Contrast");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->shadowsLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Gamma");
    item->setMinMaxStepValue(0.0, 5.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->shadowsLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Gain");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->shadowsLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Lift");
    item->setMinMaxStepValue(-1.0, 1.0, 0.01, 0.0);
    mUiItems.push_back(item);
    mUi->shadowsLayout->addWidget(item);

    // Midtones
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Saturation");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->midtonesLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Contrast");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->midtonesLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Gamma");
    item->setMinMaxStepValue(0.0, 5.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->midtonesLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Gain");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->midtonesLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Lift");
    item->setMinMaxStepValue(-1.0, 1.0, 0.01, 0.0);
    mUiItems.push_back(item);
    mUi->midtonesLayout->addWidget(item);

    // Highlights
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Saturation");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->highlightsLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Contrast");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->highlightsLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Gamma");
    item->setMinMaxStepValue(0.0, 5.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->highlightsLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Gain");
    item->setMinMaxStepValue(0.0, 4.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->highlightsLayout->addWidget(item);
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Lift");
    item->setMinMaxStepValue(-1.0, 1.0, 0.01, 0.0);
    mUiItems.push_back(item);
    mUi->highlightsLayout->addWidget(item);

    // General
    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Shadow Range");
    item->setMinMaxStepValue(0.0, 1.0, 0.01, 0.1);
    mUiItems.push_back(item);
    mUi->verticalLayout->insertWidget(4, item);

    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Highlight Range");
    item->setMinMaxStepValue(0.0, 1.0, 0.01, 0.5);
    mUiItems.push_back(item);
    mUi->verticalLayout->insertWidget(6, item);

    item = new CsSliderBoxEntity(
                UIElementType::eSliderBoxDouble,
                this);
    item->setName("Mix");
    item->setMinMaxStepValue(0.0, 1.0, 0.01, 1.0);
    mUiItems.push_back(item);
    mUi->verticalLayout->insertWidget(8, item);

    foreach(auto& item, mUiItems)
    {
        connect(item, &CsSliderBoxEntity::valueChanged,
                this, &ColorPropertiesEntity::handleValueChanged);
    }
    connect(mUi->maskCheckBox, &QCheckBox::toggled,
            this, &ColorPropertiesEntity::handleValueChanged);
    connect(mUi->clampBlackCheckBox, &QCheckBox::toggled,
            this, &ColorPropertiesEntity::handleValueChanged);
    connect(mUi->clampWhiteCheckBox, &QCheckBox::toggled,
            this, &ColorPropertiesEntity::handleValueChanged);
}

void ColorPropertiesEntity::selfConnectToValueChanged( [[maybe_unused]] NodeProperties* p)
{
//    connect(this, &ColorPropertiesEntity::valueChanged,
//            p, [p]{p->handleSomeValueChanged();});
}

QString ColorPropertiesEntity::getValuesAsString()
{
    QString vals;
    foreach(auto& item, mUiItems)
    {
        vals.append(item->getValuesAsString());
        vals.append(",");
    }
    vals.append(QString::number(mUi->maskCheckBox->isChecked()));
    vals.append(",");
    vals.append(QString::number(mUi->clampBlackCheckBox->isChecked()));
    vals.append(",");
    vals.append(QString::number(mUi->clampWhiteCheckBox->isChecked()));

    return vals;
}

void ColorPropertiesEntity::loadPropertyValues(const QString &values)
{
    auto split = values.split(",");
    for (int i = 0; i < split.size() - 3; i++)
    {
        mUiItems[i]->loadPropertyValues(split[i]);
    }

    split[split.size() - 3].toInt() == 1 ?
                mUi->maskCheckBox->setCheckState(Qt::CheckState::Checked) :
                mUi->maskCheckBox->setCheckState(Qt::CheckState::Unchecked);
    split[split.size() - 2].toInt() == 1 ?
                mUi->clampBlackCheckBox->setCheckState(Qt::CheckState::Checked) :
                mUi->clampBlackCheckBox->setCheckState(Qt::CheckState::Unchecked);
    split[split.size() - 1].toInt() == 1 ?
                mUi->clampWhiteCheckBox->setCheckState(Qt::CheckState::Checked) :
                mUi->clampWhiteCheckBox->setCheckState(Qt::CheckState::Unchecked);
}

void ColorPropertiesEntity::handleValueChanged()
{
    emit valueChanged();
}

ColorPropertiesEntity::~ColorPropertiesEntity()
{
    delete mUi;
}

} // namespace Cascade
