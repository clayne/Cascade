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

#ifndef INTPROPERTYMODEL_H
#define INTPROPERTYMODEL_H

#include "intpropertyview.h"
#include "propertymodel.h"

using Cascade::Properties::IntPropertyView;

namespace Cascade::Properties
{

class IntPropertyModel : public PropertyModel
{
    Q_OBJECT

public:
    IntPropertyModel(IntPropertyData data)
        : mData(std::make_unique<IntPropertyData>(data))
    {
        mView = new IntPropertyView();
        mView->setModel(this);
    }

    IntPropertyData* getData() override
    {
        return mData.get();
    };

    IntPropertyView* getView() override
    {
        return mView;
    };

    void setValue(const int value)
    {
        mData->setValue(value);
    }

private:
    std::unique_ptr<IntPropertyData> mData;
    IntPropertyView* mView;
};

} // namespace Cascade::Properties

#endif // INTPROPERTYMODEL_H
