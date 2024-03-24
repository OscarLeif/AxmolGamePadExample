//
// Created by oscar on 3/21/2024.
//

#ifndef AXMOLGAMEPAD_GAMECONTROLLERTEST_H
#define AXMOLGAMEPAD_GAMECONTROLLERTEST_H

#include "axmol.h"
#include "base/GameController.h"

USING_NS_AX;

class GameControllerTest : public axmol::Layer {
public:
    virtual ~GameControllerTest();

    CREATE_FUNC(GameControllerTest);

    virtual bool init();

    void onKeyDown(ax::Controller* controller, int keyCode, ax::Event* event);
    void onKeyUp(ax::Controller* controller, int keyCode, ax::Event* event);
    void onAxisEvent(ax::Controller* controller, int keyCode, ax::Event* event);

    void menuCloseCallback(Ref* sender);

private:
    float _visibleCenterX;
    float _visibleCenterY;
    float _visibleQuarterX;
    float _visibleThreeQuarterX;

    int _currControllerCount;
    typedef struct controllerHolder {
        axmol::Controller *controller;

        axmol::Node *_holderNode;

        axmol::Sprite *_leftJoystick;
        axmol::Sprite *_rightJoystick;

        axmol::Sprite *_dpadLeft;
        axmol::Sprite *_dpadRight;
        axmol::Sprite *_dpadUp;
        axmol::Sprite *_dpadDown;

        axmol::Sprite *_buttonX;
        axmol::Sprite *_buttonY;
        axmol::Sprite *_buttonA;
        axmol::Sprite *_buttonB;

        axmol::Sprite *_buttonL1;
        axmol::Sprite *_buttonR1;
        axmol::Sprite *_buttonL2;
        axmol::Sprite *_buttonR2;

        axmol::Label *_deviceLabel;
        axmol::Label *_externalKeyLabel;
    } ControllerHolder;

    ControllerHolder _firstHolder;
    ControllerHolder _secondHolder;

    axmol::Size _visibleSize;
    axmol::Vec2 _visibleOrigin;

    void registerControllerListener();

    void showButtonState(axmol::Controller *controller, int keyCode, bool isPressed);

    void createControllerSprite(ControllerHolder &holder);

    void onConnectController(Controller *controller, Event *event);

    void onDisconnectedController(Controller *controller, Event *event);

    void resetControllerHolderState(ControllerHolder &holder);

    //Keyboard
    void RegisterKeyboardListener();
    void KeyboardOnKeyPressed(axmol::EventKeyboard::KeyCode keyCode, Event* event);
    void KeyboardOnKeyReleased(axmol::EventKeyboard::KeyCode keyCode, Event* event);

};


#endif //AXMOLGAMEPAD_GAMECONTROLLERTEST_H
