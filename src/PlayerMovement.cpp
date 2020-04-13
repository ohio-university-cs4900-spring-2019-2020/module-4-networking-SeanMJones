#include "NetMsgCreateWO.h"
#ifdef AFTR_CONFIG_USE_BOOST

#include <iostream>
#include <sstream>
#include <string>
#include "AftrManagers.h"
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include "PlayerMovement.h"
#include "GLViewNewModule.h"


using namespace Aftr;

NetMsgMacroDefinition(PlayerMovement);

PlayerMovement::PlayerMovement()
{
}

PlayerMovement::~PlayerMovement()
{

}

bool PlayerMovement::toStream(NetMessengerStreamBuffer& os) const
{
    os << translation.x << translation.y << translation.z;
    os << rotation.x << rotation.y << rotation.z;
    return true;
}

bool PlayerMovement::fromStream(NetMessengerStreamBuffer& is)
{
    is >> translation.x >> translation.y >> translation.z;
    is >> rotation.x >> rotation.y >> rotation.z;
    return true;
}

void PlayerMovement::onMessageArrived()
{
    ((GLViewNewModule*)ManagerGLView::getGLView())->movePlayer(translation, rotation, false);

}

std::string PlayerMovement::toString() const
{
    std::stringstream ss;

    ss << NetMsg::toString();
    ss << "ID = " << this->id << "\n";
    return ss.str();
}

#endif