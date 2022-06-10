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

#include "nodegraphdata.h"

namespace Cascade::NodeGraph
{

NodeGraphData::NodeGraphData(QObject *parent)
    : QObject(parent)
{

}

Node* NodeGraphData::getNode(const QUuid& id) const
{
    return mNodes.at(id).get();
}

Connection* NodeGraphData::getConnection(const QUuid& id) const
{
    return mConnections.at(id).get();
}

std::unordered_map<QUuid, std::unique_ptr<Node>> const& NodeGraphData::getNodes() const
{
    return mNodes;
}

std::unordered_map<QUuid, std::shared_ptr<Connection>> const& NodeGraphData::getConnections() const
{
    return mConnections;
}

void NodeGraphData::addConnection(SharedConnection connection)
{
    mConnections[connection->id()] = connection;
}

void NodeGraphData::addNode(UniqueNode node)
{
    mNodes[node->id()] = std::move(node);
}

void NodeGraphData::deleteConnection(Connection const& connection)
{
    mConnections.erase(connection.id());
}

} // namespace Cascade::NodeGraph

