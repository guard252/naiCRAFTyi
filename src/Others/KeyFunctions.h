#ifndef NAICRAFTYI_KEYFUNCTIONS_H
#define NAICRAFTYI_KEYFUNCTIONS_H
#include <glm/glm.hpp>
#include <unordered_map>

/*
 * Hash function and equality function definitions
 * for glm::vec3 and std::pair key
 */
struct KeyFunctions
{
    size_t operator()(const glm::vec3& k)const
    {
        return std::hash<int>()(k.x) ^ std::hash<int>()(k.y)  ^ std::hash<int>()(k.z);
    }

    bool operator()(const glm::vec3& a, const glm::vec3& b)const
    {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }

    template<class T, class V>
    size_t operator()(const std::pair<T, V>& k)const
    {
        return std::hash<int>()(k.first) ^ std::hash<int>()(k.second);
    }
};

struct KeyFunctions1
{
    size_t operator()(const glm::vec2& k)const
    {
        return std::hash<int>()(k.x) ^ std::hash<int>()(k.y);
    }

    bool operator()(const glm::vec2& a, const glm::vec2& b)const
    {
        return a.x == b.x && a.y == b.y;
    }
};


#endif //NAICRAFTYI_KEYFUNCTIONS_H
