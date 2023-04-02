//
// Created by kayvee on 18.03.23.
//

#include "SceneNode.h"

SceneNode::SceneNode() {

}

void SceneNode::attachChild(SceneNode::Ptr child) {
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node) {
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
                              [&] (Ptr& p) -> bool { return p.get() == &node; });
    assert(found != mChildren.end());
    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    drawCurrent(target, states);
    for (const auto & itr : mChildren) {
        itr->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {

}

void SceneNode::update(sf::Time dt) {
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt) {

}

void SceneNode::updateChildren(sf::Time dt) {
    for(auto& child:mChildren)
        child->update(dt);
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* node = this;
         node != nullptr; node = node->mParent)
        transform = node->getTransform() * transform;
    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return getWorldTransform()*sf::Vector2f();
}

unsigned int SceneNode::getCategory() const {
    return CategoryID::Scene;
}

void SceneNode::onCommand(const Command &command, sf::Time dt) {
    if (command.category & getCategory())
        command.action(*this, dt);

    for(auto& child:mChildren)
        child->onCommand(command,dt);
}
