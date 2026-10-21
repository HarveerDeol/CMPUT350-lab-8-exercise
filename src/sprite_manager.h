#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <cstddef>
#include <deque>
#include <string>
#include <unordered_map>
#include <utility>

#include "sprite.h"
#include <SFML/Graphics.hpp>

using SpriteID = size_t;

class SpriteManager {
public:

    sf::Texture& registerTexture(const std::string& filepath) {
        return mTextures.try_emplace(filepath, filepath).first->second;
    }

    template <typename... Args>
    SpriteID createSprite(Args&&... args) {
        mSprites.emplace_back(std::forward<Args>(args)...);
        return mSprites.size() - 1;
    }

    Sprite& getSprite(SpriteID id) { return mSprites.at(id); }

private:
    std::unordered_map<std::string, sf::Texture> mTextures;
    std::deque<Sprite> mSprites; 
};

#endif  // SPRITE_MANAGER_H