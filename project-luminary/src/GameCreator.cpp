
#include "GameCreator.h"
#include "console/CharBuilder.h"
#include "palettes/ColorPalette.h"
#include "map/Enemy.h"
#include "map/ItemEntity.h"
#include "map/factory/EnemyFactory.h"
#include "map/factory/HealFactory.h"


Game *GameCreator::createNewGame() {
    Game* game = new Game({
        .map={.x=0,.y=0},
        .position={.x=24,.y=17}
    });
    game->m_torchesOrder = {
            new Torch(),
            new Torch(),
            new Torch(),
            new Torch(),
            new Torch(),
    };

    std::map<char, std::function<MapObject*()>> charMappings = {
            {
                    'G', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::DARK_BLUE)->build(), //dark
                                (new CharBuilder())->background(ColorPalette::ORANGE)->build(), //light
                                true
                                );
                    }
            },
            { // for entrances
                    'n', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::DARK_BLUE)->build(), //dark
                                (new CharBuilder())->background(ColorPalette::DARK_GREY)->build(), //light
                                false
                                );
                    }
            },
            { //water
                    'h', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::DAY_BLUE)->build(),
                                true
                                );
                    }
            },
            { //wall
                    'r', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::HOUSE)->build(),
                                true
                                );
                    }
            },
            { //planter
                    'o', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::TRUNK)->build(),
                                false
                                );
                    }
            },
            {
                    'i', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::LIGHT_BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::PATH)->build(),
                                false
                                );
                    }
            },
            {
                    's', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::LIGHT_BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::DAY_BLUE)->build(),
                                false
                                );
                    }
            },
            {
                    'j', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::DARK_GREEN)->build(),
                                (new CharBuilder())->background(ColorPalette::GREEN)->build(),
                                true
                                );
                    }
            },
            {
                    'k', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::GREEN)->build(),
                                (new CharBuilder())->background(ColorPalette::TREE_GREEN)->build(),
                                true
                                );
                    }
            },
            {
                    'l', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::BG_COLOR)->build(),
                                (new CharBuilder())->background(ColorPalette::DAY_GREEN)->build(),
                                false
                                );
                    }

            },
            {
                    'w', []() {
                        return new MapObject(
                                (new CharBuilder('w'))->background(ColorPalette::BG_COLOR)->foreground(ColorPalette::BLUE)->build(),
                                (new CharBuilder('w'))->background(ColorPalette::DAY_GREEN)->foreground(ColorPalette::GREEN)->build(),
                                false
                                );
                    }
            },
            {
                    '~', [] () {
                        return new MapObject(
                                (new CharBuilder('~'))->background(ColorPalette::BLUE)->foreground(ColorPalette::LIGHT_BLUE)
                                ->format(BLINKING)->build(),
                                (new CharBuilder('~'))->background(ColorPalette::DAY_BLUE)->foreground(ColorPalette::LIGHT_BLUE)
                                ->format(BLINKING)->build(),
                                true
                                );
                    }
            },
            {
                    'c', [] () {
                        return new MapObject(
                                (new CharBuilder('"'))->background(ColorPalette::DAY_GREEN)->foreground(ColorPalette::CARROT)
                                ->format(INVERTED)->format(BLINKING)->build(),
                                (new CharBuilder('"'))->background(ColorPalette::CARROT)->foreground(ColorPalette::DAY_GREEN)
                                ->format(BLINKING)->build(),
                                true
                                );
                    }
            },
            {
                    'd', [] () {
                        return new MapObject(
                                (new CharBuilder('_'))->background(ColorPalette::LIGHT_BLUE)->foreground(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder('_'))->background(ColorPalette::TRUNK)->foreground(ColorPalette::BROWN)->build(),
                                false
                        );
                    }
            },
            { //planter
                    'p', [] () {
                        return new MapObject(
                                (new CharBuilder('_'))->background(ColorPalette::BLUE)->foreground(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder('_'))->background(ColorPalette::TRUNK)->foreground(ColorPalette::ORANGE)->build(),
                                false
                                );
                    }
            },
            {
                    '|', [] () {
                        return new MapObject(
                                (new CharBuilder('|'))->background(ColorPalette::LIGHT_BLUE)->foreground(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder('|'))->background(ColorPalette::DAY_BLUE)->foreground(ColorPalette::BLUE)->build(),
                                false
                                );
                    }
            },
            {
                    '_', [] () {
                        return new MapObject(
                                (new CharBuilder('_'))->background(ColorPalette::LIGHT_BLUE)->foreground(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder('_'))->background(ColorPalette::DAY_BLUE)->foreground(ColorPalette::BLUE)->build(),
                                false
                                );
                    }
            },
            {
                    'g', [] () {
                        return new MapObject(
                                (new CharBuilder('\\'))->background(ColorPalette::DARK_BLUE)->foreground(ColorPalette::BLUE)->build(),
                                (new CharBuilder('\\'))->background(ColorPalette::ROOF)->foreground(ColorPalette::ORANGE)->build(),
                                true
                                );
                    }
            },
            {
                    '=', [] () {
                        return new MapObject(
                                (new CharBuilder('='))->background(ColorPalette::DARK_BLUE)->foreground(ColorPalette::BLUE)->build(),
                                (new CharBuilder('='))->background(ColorPalette::ROOF)->foreground(ColorPalette::ORANGE)->build(),
                                true
                                );
                    }
            },
            {
                    'm', [] () {
                        return new MapObject(
                                (new CharBuilder('/'))->background(ColorPalette::DARK_BLUE)->foreground(ColorPalette::BLUE)->build(),
                                (new CharBuilder('/'))->background(ColorPalette::ROOF)->foreground(ColorPalette::ORANGE)->build(),
                                true
                                );
                    }
            },
            {
                    'q', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::TRUNK_GREEN)->build(),
                                (new CharBuilder())->background(ColorPalette::TRUNK)->build(),
                                true
                                );
                    }
            },
            {
                    't', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::DARK_GREEN)->build(),
                                (new CharBuilder())->background(ColorPalette::LIGHT_GREY)->build(),
                                true
                                );
                    }
            },
            {
                    'u', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::DARK_GREY)->build(),
                                true
                                );
                    }
            },
            {
                    'v', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::BROWN)->build(),
                                true
                                );
                    }
            },
            {
                    'y', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::LIGHT_BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::LIGHT_GREY)->build(),
                                true
                                );
                    }
            },
            { //fire
                    'x', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::YELLOW)->build(),
                                true
                                );
                    }
            },
            { //fire
                    'z', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::ORANGE)->build(),
                                true
                                );
                    }
            },
            {
                '0',[&game]() { return game->m_torchesOrder.at(0);},
            },
            {
                '1',[&game]() { return game->m_torchesOrder.at(1);},
            },
            {
                '2',[&game]() { return game->m_torchesOrder.at(2);},
            },
            {
                '3',[&game]() { return game->m_torchesOrder.at(3);},
            },
            {
                '4',[&game]() { return game->m_torchesOrder.at(4);},
            }


    };

    std::string MAP_1 =
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllwwllllllllllllllG==Glllwlllllllllllllllllllllllllllllllllllllllllwllllllll\n"
            "lllllllllwwllllrrrllGmm==ggGllllllllwwlllllllllkkllllllllllwwllllwwwllllllllllll\n"
            "lllllllllllllllrrrGmmmm==ggggGllllllllwlllllllkkkkllllwwwwllwwllllllllllwlllllll\n"
            "llllwllllllllllrrrmmmmm==ggggggGllllllllllllkjjkkjjkllllwlwlllllllllllwwwwwlllll\n"
            "llllllllllllllGrrrmmmmm==ggggggggGlllllllllkkkjjjjkkklllllllllllllllllllllllllll\n"
            "llllllllllllGmmrrmmmmmGrrGgggggggggGllllllljjkkkkkkjjllllliiiiiiiiiiiiiiiillllll\n"
            "llllllllllllmmmmmmmmGrrrrrrGgggggggglllllllljjjjjjjjllliiiiiiiiiiiiiiiiiiiiiilll\n"
            "llllllllllllmmmmmmGrrrrrrrrrrGgggggglllllllllllqqlllliiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllllkkllllmmmmGrrrrrrrrrrrrrrGggggllpopoppplllllliiiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "lllllkkkklllmmGrrrrrr_|__|_rrrrrrGggllopppopolllllliiiiiiiiiilllllllllllliiiiiii\n"
            "lllkjjkkjjklllrrrrrrrs|ss|srrrrrrrllllopopppplllliiiiiiiiiilllllllwwwwllllllliii\n"
            "llkkkjjjjkkkllrrrrrrrrrrrrrrrrrrrrlllloopoopolllliiiiiiiiiilllllwwwkkwllllllllll\n"
            "lljjkkkkkkjjllr__|__rGGGGGGr__|__rllllppoppoplllliiiiiiiiiilllllllkkkkllllllllll\n"
            "llljjjjjjjjlllrss|ssrGGGGGirss|ssrllllllllllllllliiiiiiiiiilllllkjjkkjjkllllllll\n"
            "llllllqqllllllrrrrrrrGGGGGGrrrrrrrllllwwllllllliiiiiiiiiillllllkkkjjjjkkklllllll\n"
            "llllllwllllwlllllllliiiiiiiilllllllllwwlllwlllliiiiiiiiiilllllljjkkkkkkjjlllllll\n"
            "llllllllwwwwwwwllllliiiiiiiiillllllllllllllllliiiiiiiiiiillllllljjjjjjjjllllwlll\n"
            "llllllwlllwwlllllllllliiiiiiiiillllllllllllliiiiiiiiiiiiilllllwwlllqqlllllllllll\n"
            "llllllllllllllwwlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllllllllllllllliiii\n"
            "iiiillllllllllllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiillllllwwlllwlllllliiiiiihhhh\n"
            "hhhhiiiiiilllllwwwllllllllliiiiiiiiiiiiiiiiiiiiiiillllllwwwwwlllliiiiihhhhhhh~hh\n"
            "hhhhhhhhhhiiiiiiiiiiillwlllllllllllllllllllllllllllllwllllliiiiiihhhhhhhhh~hhhhh\n"
            "hhhh~h~h~hhhhhh~hhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiihhhhhh~h~h~hh~hh~hhhh\n"
            "hhhhh~h~hhhhhhhh~hhhhhhhhhhhhh~hhhhhhhh~hhhhhhhhhhhhhhhhhhhhhhhhhh~h~hhhhhhhhhhh\n";

    std::string MAP_2 =
            "lllllllllllllllllllllllllllllllllllllllllllllllllllllllwlwllllllllllllllllllllll\n"
            "lllllwlllwllllllllllllllwlllwlllllllllllllllllllllllwlllllllwlwwllllllllllllllll\n"
            "llllllllkkkkklllllllllwllllllllllllllllllllllhhhhhhhhhhhhhhhhllllllwllllllwwllll\n"
            "llllllkkkkkkkkjllllwlllllllllllllllllhhhhhhhhh~~hh~hh~hhhh~hhhhhhhllllllllllllll\n"
            "lllljjjjjjjjjjjjlllllllllllliiiiiiiddddddddddddddddddhhh~hhhhhhhhhhhhhhlllllllll\n"
            "llllllllllwlllllllwlllllliiiiiiiiiiddddddddddddddd0ddhhhhhh~~hh~hhhhhhhhhhhlllll\n"
            "llllllwwlllllllllllllliiiiiiiiiiiiiddddddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhlll\n"
            "llllllllllllllllliiiiiiiiiiiiiiiiiiddddddddddddddddddhhhhhhhhh~hh~hhh~~hhhhhhlll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllllhhh~~hh~hhhhhhhvvhhh~hh~hhhhhhhhhhhhhhhhllll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiillllllllllhhhhhhh~~hh~hhhhh~hhhhhhh~hh~hhhhhh~hhhhllll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiillllwlllllhhhhhhhhhhhhhh~hhhh~~hhhhhh~hhhh~hhhhhhhllll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiillllllwlllllhhhhhh~hhhhhhhhhh~~hhhhhhh~hhhhhhhllllll\n"
            "llllllllliiiiiiiiiiiiiiiiiiiiillllllllllllllhhhhhhh~~hhhhhh~hhh~hhhhhhhhhlllwlll\n"
            "llllllkklllllllliiiiiiiiiiiiiiiillwllllllllllllllhhhhhh~~hhhh~hhhh~h~hhhhllwllll\n"
            "lllllkkkkllllwlllliiiiiiiiiiiiiilllwwllllllllllllllllhhhhh~~hh~hhhhhhhhhhlllllll\n"
            "lllkjjkkjjkllllllllliiiiiiiiiiiilllllllllllkkllllllllllllhhhhhhhhh~hhhhhllwllwll\n"
            "llkkkjjjjkkkllwwwwlliiiiiiiiiiiiilllllwlllkkkklllllwwlllllllhhhhhhhhhhlllllwllll\n"
            "lljjkkkkkkjjlllllllllliiiiiiiiiiiilwllllkjjkkjjkllllllwlllllllllllllllllllllllll\n"
            "llljjjjjjjjllllllllllliiiiiiiiiiiilllllkkkjjjjkkklllllllwwllllllwllllkklllwlllll\n"
            "llllllqqllllllllllwllliiiiiiiiiiiillwlljjkkkkkkjjllwwlllllllllllllllkkkkllllllll\n"
            "llllllllllkkkkjlllwllliiiiiiiiiiiilllllljjjjjjjjllllllllllllllllllkjjkkjjklllwll\n"
            "lllwllllkkkkkkkkjlllliiiiiiiiiiiiilwwllllllqqllllwllllkkkkkjlllllkkkjjjjkkklllll\n"
            "lllllljjjjjjjjjjjjlliiiiiiiiiiiiilllwlllllllllllllllkkkkkkjjjllljjjkkkkkjjjjllll\n"
            "lllwlllllllwlllllllliiiiiiiiiiiiillllllwlwlllllwllljjjjjjjjjjjlllljjjjjjjjllllll\n"
            "lllllllllllllllllllliiiiiiiiiiiiillllllllllllllllllllllllllllllllllllqqlllllllll\n";

    std::string MAP_3 =
            "lllllllllllllllllllliiiiiiiiiiiiilllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllkkkklllllllwwlliiiiiiiiiiiiiillllwllllwwwwwwllwllllllllllwwwllllllllwwllll\n"
            "llllkkkkkjjjlllwllllliiiiiiiiiiiiiillwwlllllllwlllllllwllllllwwwlllllwllllllllll\n"
            "llljjjjjjjjjjlllllwlllliiiiiiiiiiiiillllllwwlllllwlllllllllllliiiiiiiiiiiiiiiiii\n"
            "lllllllllllwwwlllllllwlliiiiiiiiiiiilllwwwllwllliiiiiiiiiiiiiihhhhhhhhhhhhhhhhhh\n"
            "lllllwwwwlllllwwlllllllliiiiiiiiiiiilllllllliiiihhhhhhhhh~hhhhhhhh~~hhhhhhhhhhhh\n"
            "llllllwlllwllllliiiiiiiGGiiiiiiiiiiGGiiiiiiihhhhh~~~hhh~hhhh~~h~hhhhh~hh~hhhhhhh\n"
            "lllllliiiiiiiiiihhhhhhhGGiiiiiiiiiiGGhhhhhhhhhhhhhh~hhhhh~~hhhhhhh~hhh~hhhh~hhhh\n"
            "iiiiiihhhhhhhhhhhhh~~hhGGiiiiiiiiiiGGhhh~~h~~hhhhhh~hhh~hhhh~hhh~hhh~~hhhhhhhhhh\n"
            "hhhhhhhhh~~hhh~hhhhhhhhGGiiiiiiiiiiGGhhhhhhhhhhhhhhhhhhhhhhhhhhhhh~hhhhhhh~hhhhh\n"
            "hhh~~hhhhhhhh~hhhh~hhhhGGiiiiiiiiiiGGhhhhh~~hh~hhhh~~~~hhhh~~hhhhkk~hhhhhhhhhhhh\n"
            "hhhhh~~hh~hhhhhh~~hhhhhGGiiiiiiiiiiGGhhhhhhh~~hhhhhhhh~hhhhhhhhhkkkkhhhhiiiiiiii\n"
            "h~hhhhhhhhhhhh~hhhhhhhhGGiiiiiiiiiiGGhhhhhhhhhhhhhhhhhhhhiiiiikjjkkjjkiillllllll\n"
            "hhh~~hhh~hhh~~hhhhhhhhhGGiiiiiiiiiiGGiiiiiiiiiiiiiiiiiiiillllkkkjjjjkkkllllwllll\n"
            "hhhhh~~hhhhhhhhhhiiiiiiGGiiiiiiiiiiGGlllwwllllkkllllllllllllljjkkkkkkjjllllwllll\n"
            "hhh~hhhh~hhhhhhilllllllliiiiiiiiiiiillllllwllkkkkllllwwwlllllljjjjjjjjlllwwwllll\n"
            "hhhhhh~hhhhhhhilwwwllllliiiiiiiiiiiiiilllllkjjkkjjklllllwllllllllqqlllwwllllllll\n"
            "hhh~hhhhhhhhhhillllwwllllliiiiiiiiiiiiilllkkkjjjjkkklllllllwlllllwwlllkkkkllllll\n"
            "hhhhh~hhh~~hhhhhilllwll1lliiiiiiiiiiiiiilljjkkkkkkjjllwllllkklllllllkkkkkjjjllll\n"
            "hhhhhhh~hhhhhhhhillllwwwllliiiiiiiiiiiiillljjjjjjjjlllllllkkkkllllljjjjjjjjjjlll\n"
            "hhh~~hhhhhhhhhhhilwwlllllllliiiiiiiiiiiiilllllqqllllllwlkjjkkjjkllllllllllllllll\n"
            "hhhhh~hhh~~hhhhhhiilwwwllwlliiiiiiiiiiiiillwwwwwlllwlllkkkjjjjkkklllwwlllwlwllll\n"
            "hhhhhhh~hhh~~hhhhiillllwwllliiiiiiiiiiiiillllllwwlllllljjkkkkkkjjllllwwwwlllllll\n"
            "hhh~~hhhh~hhhh~hhhhiillllliiiiiiiiiiiiiilllllllllllwwllljjjjjjjjllllwllllllwwlll\n"
            "hhhhhhhhhhhhhhhhhhhiillliiiiiiiiiiiiiillllwwllwllllllllllllqqlllllllllllllllllll\n";

    std::string MAP_4 =
            "hhhhhh~~hhhhhhhhhhhhillliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhh~hhh~hhhhhhhhilliiiiiiiiiiiiiilllllllwwwwlwlllllwwllllllllwwlllkkllwllll\n"
            "hhhhhhhhhhh~hhhh~hhhhilllliiiiiiiiiiiiiillllllllllllkklllllwllwlllllllkkkkllllll\n"
            "hhhhh~~hhhhhhhhhhhhhhilllliiiiiiiiiiiiiiiiilwllwlllkkkkllllllwllllllkjjkkjjkllwl\n"
            "hhhhhhhhhh~~hhh~hhhhhiwllliiiiiiiiiiiiiiiiillllllkjjkkjjkllllluuuuuuuuuujjkkklll\n"
            "hhhhhhhhhhhhh~hhhhhhhilllllliiiiiiiiiiiiiiiiiiilkkkjjjjkkklluutttttttttuuukjllll\n"
            "iihhhhhhhh~hhhhhhhhhhilwlllliiiiiiiiiiiiiiiiiiiljjkkkkkkjjuuttttttttttttttuullll\n"
            "lliihhhhhhh~hhh~~hhhhiillwwlllllkkiiiiiiiiiiiiilljjjjjjjjluttttttttttttttttuuull\n"
            "lllliihhhhhhh~hhhhhhhhhilllllllkkkkiiiiiiiiiiiiillllqqluuutttttttttttttttttttuul\n"
            "lllllihhhhhhhhhhhhhhhhhilllllkjjkkjjkiiiiiiiiiiillwllluutttttttttnnnnnttttttttuu\n"
            "lllwllihhh~~hhhh~hhhhhhhilwlkkkjjjjkkkiiiiiiiiiiilllluttttttttttnnnnnnnntttttttt\n"
            "llwlllihhhhhh~hhhh~hhhhhillljjkkkkkkjjiiiiiiiiiiilllutttttttttnnnnnnnnnnnttttttt\n"
            "llllkkkiiihhhhh~~hhhhhhhilllljjjjjjjjllliiiiiiiiillluttkkkkjtnnnnnn2nnnnnntttttt\n"
            "llkkjjjjkkiihhhhhh~hh~hhhillllllqqlllllliiiiiiiiillljkkkkkkkjnnnnnnnnnnnnntttttt\n"
            "lkjjjjjjjjkkiGGGGGGGGGGGGGGlllwllllllliiiiiiiiiiilljjjjjkkkkkjlwlllllllwllllllll\n"
            "lllllllllllGGGiiiiiiiiiiiiGGGllllliiiiiiiiiiiiiillwllllllwlwwllllwlllwwllwllllll\n"
            "lllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllwlwwlllllwllllwllllkkllwlll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllllllllllllwllllkkkklllll\n"
            "iiiiiiiiiiiiiGGGGGGGGGGGGGGiiiiiiiiiiiiiiiilllllllkklllllwwwlllllllllkjjkkjjklll\n"
            "iiiiiiiiiiiGGGhh~~hhhhhhhiGGGlllllwlwlwwllwllllljkkkkjlllllwllllwlllkkkjjjjkkkll\n"
            "iiiikkillllllihhhh~hhhhhhilllllllllwlllllllllllkjjkkjjkllllllllllllljjkkkkkkjjll\n"
            "lllkkkklllllihhhhhhh~~hhhilllllwwllllllwllllllkkkjjjjkkkllwwllllllllljjjjjjjjlll\n"
            "lkjjkkjjklllihhhh~hhhhhhhhilllllllwlwllllllllljjkkkkkkjjlllllwllllllllllqqllllll\n"
            "kkkjjjjkkkihhh~hhh~hh~~hhhillllllllllwwllwllllljjjjjjjjlllwlllllllwllllllwwlllll\n"
            "lkkkkkkkklihhhhhh~~hhhhh~hilllllllllllllllllllllllqqlllllllllllwllllllllllllllll\n";

    std::string MAP_5 =
            "lllllllllllllllllllllllllllllliiiiiiiiiiillllllllllllllllllllllllllihhhhhhh~hhhh\n"
            "lllllllkkllllllwwwllwlwwlllllliiiiiiiiiiilwlwlwwlllllllllllwllllwwwliihh~~hh~hhh\n"
            "llllllkkkkllllllllwllllwllllliiiiiiiiiiiilllwllllkklllllllllwwwllllwwliihhh~hhhh\n"
            "llllkjjkkjjklllllllllwwlllllliiiiiiiiiiiilwlllllkkkklllllllllllwllwllllliiihhh~h\n"
            "lllkkkjjjjkkklllwllllllllllliiiiiiiiiiiiilllllkjjkkjjkllllllllllllllllllllliihhh\n"
            "llljjkkkkkkjjlllllllwlllliiiiiiiiiikkiillllllkkkjjjjkkklllllwwwlllllllwllllllihh\n"
            "lllljjjjjjjjlllllllliiiiiiiiiiiiiikkkklllllljjkkkkkkkkjjllwwllllllllllllllllllii\n"
            "lllllllqqllllllliiiiiiii3iiiiiiikjjkkjjkllllljjjjjjjjjjllllllllllllkklllwwllllll\n"
            "llllllllllllliiiiiiiiiiiiiiiiilkkkjjjjkkkllllllllqqllwwwlllwllllllkkkkllllwlllll\n"
            "lllwlllllliiiiiiiiiiiiiiilllllljjkkkkkkjjwllllwllllllllllwlllwllkjjkkjjkllllllll\n"
            "lllllwwliiiiiiiiiiiiiiiikkkllllljjjjjjjjllwwwlllkkkkllllwllllllkkkjjjjkkklllwlll\n"
            "lllllllliiiiiiiiiiiiiiikkkkklllllwlqqllwwwlllljjjkkkkkllllllllljjkkkkkkjjllwwlll\n"
            "klllwllliiiiiiiiiiiiikjjkkkjjkllllllwlllllllljjjjjjjjjjjlllllllljjjjjjjjlwllllll\n"
            "jjkllllliiiiiiiiiiiikkkjjjjjkkkllllllllllllllllllllllllllllllllllllqqlllllllwlll\n"
            "jkkklllliiiiiiiiiiiijjkkkkkkkjjllllllllliiiiiiiiiiiillllllllllllllllllllwwwlllll\n"
            "kkjjllllliiiiiiiiiiiijjjjjjjjjlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiillllwllllllllll\n"
            "jjjwwllllliiiiiiiiiiiillqqqlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllll\n"
            "lllllwllllliiiiiiiiiiiillllllliiiiiiiiiiiiiiiiiiiiikkiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllwlllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilkkkklllliiiiiiiiiiiiiiiiiiiiii\n"
            "llllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllkjjkkjjklliiiiiiiiikkiiiiiiiiiii\n"
            "llllllkkklllllliiiiiiiiiiiiiiiiiiiiiiiiiiilllllkkkjjjjkkkllllllllikkkkiiiiiiiiii\n"
            "llllkkkkkjjlllllllliiiiiiiiiiiiiiiiiiillllwwllljjkkkkkkjjlllllllkjjkkjjklwwlllll\n"
            "llljjjkjjjjkklllkklwwlllwlwllllllllllllllllllwlljjjjjjjjlllllllkkkjjjjkkklllllll\n"
            "lllllllllllllllkkkkllwlwllllwlwwwllllkkllllllllllllqqlllllllllljjkkkkkkjjlllllll\n"
            "lllllllllllllkjjkkjjkllllllwllllllllkkkklllllllllllllllllllllllljjjjjjjjllllllll\n";

    std::string MAP_6 =
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhzhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hh~hhhhhhh~hhhhhh~hhhhhhhhhh~hhh~h~hhhhx~hhhhhh~hhhhhhhhh~hhhhhhh~hhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhh~hhhhhhhhhhhhhhhhxxhzhhhhhhhhhhhhhhhhhhhhhhhhh~~hhhhhhhhhhhh\n"
            "hhhhhh~~hhhhhhh~hhhhhhhhhhhhhhhhhhhhxxxxzhhhhhhhhhhhhhhhhhh~~hhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhh~~hhh~~hhhhhhhhyyyxxzyyyhhhhhhhhhh~hhhhhhhhhhhhhhhh~hhhhhhhhh\n"
            "hhh~hhhhhhh~h~~hhhhhhhhhhhhhhhhhhhhuyyyyyuhhhhhh~~hhhhhhhhhhhhhhh~hhhhhhhhh~hhhh\n"
            "hhhhhhhhhhhhhhhhh~hhhhhhhhhhhhhhhhhhuuuuuhhhhhhhhhhhhhhhhh~hhhhhhhhhh~~hhhhhhhhh\n"
            "hhhhh~h~~hhhh~hhhhhhhhhhhhhhhhiiiuuiiuuuiiuuiiiiiiiiiiihhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "kh~hhhhhhh~hhhhhhhhhhhiiiiiiiiilluuuuuuuuuuulllllllllliiiiiihhhhhh~hhhhh~hhhhhhh\n"
            "kkhhhhhhhhhhiikkiiiiuuiuuuluullllrruurrruurrlllluuluuuluullliiiihhhhhhhhhhhhhhhh\n"
            "kjjkiiiiiiiiikkkkllluuuuuuuuullllrrrrrrrrrrrlllluuuuuuuuulllwlwliiiiiiiihh~~hhhh\n"
            "jjkkkllllllkjjkkjjklrrurrrurrlllllrrurrrurrlllllrrurrrurrllllllllllllllliihhhhhh\n"
            "kkkjjlllllkkkjjjjkkklrrrrrrrllllllrrrrrrrrrllllllrrrrrrrlllllwllllllllllllih~hhh\n"
            "jjjjlllrrlrrkrrkrrkrrlrrurrlllllllrrurrrurrlllllllrrurrlrrlrrlrrlrrlrrlllllihhhh\n"
            "qllllllrrrrrrrrrrrrrrurrrrrlllllllrrrrrrrrrlllllllrrrrrurrrrrrrrrrrrrrlllllihhhh\n"
            "lllllllrrrrrrrrrrrrrrurrurrlllllllrrrnnnrrrlllllllrrurrurrrrrrrrrrrrrrlllllihh~h\n"
            "llllllkkrrrrrrrrrrrrrurrrrrlllllllrrnn4nnrrlllllllrrrrrurrrrrkkrrrrrrrlllllihhhh\n"
            "lllllkkkkllllllllllllrrrkkrrllllllrrnnnnnrrllllllrrrrrrrllllkkkkllllllllwllihhhh\n"
            "lllkjjkkjjkllllwwllllllkkkkllllllllliiiiilllllllllllllllllkjjkkjjklllllllllih~hh\n"
            "llkkkjjjjkkkllllllwwlkjjkkjjkllllliiiiiiillllwlllwwwlllllkkkjjjjkkkllllllllihhhh\n"
            "lljjkkkkkkjjllllllllkkkjjjjkkklllliiiiiillllllllwlllllllljjkkkkkkjjllllwlllihhhh\n"
            "llljjjjjjjjlllllwllljjkkkkkkjjllllliiiiiiillllkkkllllllllljjjjjjjjllllwwiiiihhhh\n"
            "llllllqqlllllllllllwwjjjjjjjjlllllliiiiiiillljkkkkkkllwllllllqqllllllliihhhhhhhh\n"
            "llllllllllllllllllllllllqqlwwllllliiiiiiillljjjjjjjjjjlllllllllllllwiihhhhhhhhhh\n"
            "lllllllllllllllllllllllllllllllllliiiiiiiilllllllllllllllllllllllllihhhhhhhhhhhh\n";

    EnemyFactory* enemyFactory = new EnemyFactory();
    HealFactory* healFactory = new HealFactory();

    std::string EMPTY_MAP;
    game->m_mapMatrix = {
            {
                new Map(MAP_1, charMappings, { //x sloupce, y radky
                    enemyFactory->createEnemy({.x=65,.y=7}, EASY),

                    healFactory->createHeal({.x=39, .y=12}),
                    healFactory->createHeal({.x=42, .y=9}),
                    healFactory->createHeal({.x=41, .y=11}),
                    healFactory->createHeal({.x=44, .y=10}),
                    healFactory->createHeal({.x=40, .y=10}),
                    healFactory->createHeal({.x=43, .y=13}),

                }),
                new Map(MAP_2, charMappings,{
                    enemyFactory->createEnemy({.x=33, .y=5}, EASY),
                    enemyFactory->createEnemy({.x=27, .y=19}, EASY),

                    healFactory->createHeal({.x=55, .y=18}),
                    healFactory->createHeal({.x=14, .y=15}),
                    healFactory->createHeal({.x=21, .y=4}),
                    healFactory->createHeal({.x=47, .y=5}),

                })
            },
            {
                new Map(MAP_6, charMappings,{
                    enemyFactory->createEnemy({.x=38, .y=17}, HARD),
                    enemyFactory->createEnemy({.x=39, .y=16}, HARD),
                    enemyFactory->createEnemy({.x=37, .y=16}, HARD),
                    enemyFactory->createEnemy({.x=37, .y=21}, MEDIUM),
                    enemyFactory->createEnemy({.x=38, .y=15}, MEDIUM),
                    enemyFactory->createEnemy({.x=38, .y=19}, MEDIUM),

                    healFactory->createHeal({.x=46, .y=15}),
                    healFactory->createHeal({.x=56, .y=22}),
                    healFactory->createHeal({.x=18, .y=18}),

                }),
                new Map(MAP_3, charMappings,{
                    enemyFactory->createEnemy({.x=30, .y=15}, EASY),
                    enemyFactory->createEnemy({.x=28, .y=14}, MEDIUM),
                    enemyFactory->createEnemy({.x=32, .y=14}, MEDIUM),

                    healFactory->createHeal({.x=45, .y=3}),
                    healFactory->createHeal({.x=67, .y=21}),
                    healFactory->createHeal({.x=3, .y=6}),
                    healFactory->createHeal({.x=30, .y=17}),

                })
            },
            {
                new Map(MAP_5, charMappings,{
                    enemyFactory->createEnemy({.x=16, .y=14}, HARD),
                    enemyFactory->createEnemy({.x=33, .y=3}, MEDIUM),
                    enemyFactory->createEnemy({.x=59, .y=16}, MEDIUM),
                    enemyFactory->createEnemy({.x=35, .y=19}, MEDIUM),
                    enemyFactory->createEnemy({.x=13, .y=10}, HARD),

                    healFactory->createHeal({.x=57, .y=5}),
                    healFactory->createHeal({.x=70, .y=14}),
                    healFactory->createHeal({.x=40, .y=12}),
                    healFactory->createHeal({.x=20, .y=4}),
                    healFactory->createHeal({.x=20, .y=20}),
                    healFactory->createHeal({.x=45, .y=16}),

                }),
                new Map(MAP_4, charMappings,{
                    enemyFactory->createEnemy({.x=67, .y=13}, MEDIUM),
                    enemyFactory->createEnemy({.x=69, .y=12}, MEDIUM),
                    enemyFactory->createEnemy({.x=65, .y=12}, MEDIUM),
                    enemyFactory->createEnemy({.x=67, .y=11}, MEDIUM),

                    healFactory->createHeal({.x=58, .y=3}),
                    healFactory->createHeal({.x=65, .y=23}),
                    healFactory->createHeal({.x=32, .y=21}),
                    healFactory->createHeal({.x=2, .y=9}),
                    healFactory->createHeal({.x=64, .y=16}),

                })
            }
    };
    return game;
}
