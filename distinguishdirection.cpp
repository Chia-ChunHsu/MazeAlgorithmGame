#include "distinguishdirection.h"

DistinguishDirection::DistinguishDirection()
{
    std::vector<bool> path;
    for(int i=0;i<3;i++)
        path.push_back(false);
    _path.assign(path.begin(),path.end());
}

DistinguishDirection::DistinguishDirection(std::vector<bool>& path)
{
    assert(path.size()==3);  // Right, Fontal, Left Direction
    _path.assign(path.begin(),path.end());
}

int DistinguishDirection::DisinguishRighWallFollowing()
{
    for(int i=0;i<_path.size();i++)
    {
        if(_path[i] == true)
        {
            return i;
        }
    }
    return 3;
}
