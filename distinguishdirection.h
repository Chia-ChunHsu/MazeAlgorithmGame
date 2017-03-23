#ifndef DISTINGUISHDIRECTION_H
#define DISTINGUISHDIRECTION_H

#include <cassert>
#include <vector>
class DistinguishDirection
{
public:
    DistinguishDirection();

    DistinguishDirection(std::vector<bool>& path);

    int DisinguishRighWallFollowing();
private:
    std::vector<bool> _path;
};

#endif // DISTINGUISHDIRECTION_H
