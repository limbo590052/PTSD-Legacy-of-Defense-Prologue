//
// Created by limbo on 2025/3/20.
//

#ifndef PTSD_LEGACY_OF_DEFENSE_PROLOGUE_FIXER_HPP
#define PTSD_LEGACY_OF_DEFENSE_PROLOGUE_FIXER_HPP
#include "Util/Position.hpp"

class Fixer {
public:
    static Util::PTSDPosition CorrectCursorPosition(const Util::PTSDPosition &cursorPosition){
        Util::PTSDPosition truePosition = {cursorPosition.x, -cursorPosition.y};
        return truePosition;
    }
};


#endif //PTSD_LEGACY_OF_DEFENSE_PROLOGUE_FIXER_HPP
