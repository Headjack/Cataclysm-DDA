#include "character.h"

Character::Character()
{
    Creature::set_speed_base(100);
};

Character::~Character()
{
};

field_id Character::bloodType() const
{
    return fd_blood;
}
field_id Character::gibType() const
{
    return fd_gibs_flesh;
}

bool Character::is_warm() const
{
    return true; // TODO: is there a mutation (plant?) that makes a npc not warm blooded?
}

const std::string &Character::symbol() const
{
    static const std::string character_symbol("@");
    return character_symbol;
}

void Character::store(JsonOut &jsout) const
{
    Creature::store( jsout );
    // Add members of this class here:
}

void Character::load(JsonObject &jsin)
{
    Creature::load( jsin );
    // Add members of this class here:
}

bool Character::move_effects()
{
    if (has_effect("downed")) {
        if (rng(0, 40) > get_dex() + int(get_str() / 2)) {
            add_msg_if_player(_("You struggle to stand."));
            return false;
        } else {
            add_msg_if_player(_("You stand up."));
            remove_effect("downed");
            return false;
        }
    }
    return Creature::move_effects();
}
void Character::add_effect(efftype_id eff_id, int dur, body_part bp, int intensity, bool permanent)
{
    Creature::add_effect(eff_id, dur, bp, intensity, permanent);
}
