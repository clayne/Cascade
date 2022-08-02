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

#include "folderboxentity.h"
#include "ui_folderboxentity.h"

#include <QFileDialog>

namespace Cascade {

FolderBoxEntity::FolderBoxEntity(UIElementType et, QWidget *parent) :
    UiEntity(et, parent),
    mUi(new Ui::FolderBoxEntity)
{
    mUi->setupUi(this);

    mUi->lineEdit->setText(QCoreApplication::applicationDirPath());

    connect(mUi->pushButton, &QPushButton::clicked,
            this, &FolderBoxEntity::handleFolderButtonClicked);
}

const QString FolderBoxEntity::name()
{
    return mUi->label->text();
}

void FolderBoxEntity::setName(const QString &name)
{
    mUi->label->setText(name);
}

void FolderBoxEntity::selfConnectToValueChanged( [[maybe_unused]] NodeProperties *p)
{
//    connect(this, &FolderBoxEntity::valueChanged,
//            p, [p]{p->handleSomeValueChanged();});
}

QString FolderBoxEntity::getValuesAsString()
{
    return "\"" +  mUi->lineEdit->text() + "\"";
}

void FolderBoxEntity::loadPropertyValues(const QString &values)
{
    Q_UNUSED(values);
}

void FolderBoxEntity::handleFolderButtonClicked()
{
    QFileDialog dialog(nullptr);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setDirectory(QCoreApplication::applicationDirPath());
    if (dialog.exec())
    {
        mUi->lineEdit->setText(dialog.selectedFiles().at(0));
    }
}

FolderBoxEntity::~FolderBoxEntity()
{
    delete mUi;
}

} // namespace Cascade
