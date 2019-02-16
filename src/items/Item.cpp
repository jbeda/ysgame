#include "Item.hpp"
#include "../Game.hpp"
#include "../Player.hpp"
#include "../util/debugging/notif.h"

void Item::Update() {

	if (this->Collided(Plane::X, *gGame->getPlr()) && 
		this->Collided(Plane::Y, *gGame->getPlr())) {
		this->form->Activate();
		if (gGame->getInput()->GetPickup()) {
			// Hand off ownership of effect to player
			gGame->getPlr()->AddEffect(this->effect);
			this->effect = NULL;
			this->dead = true;
			DebugMessage("picked up item");
			this->form->Deactivate();
		}
	} else {
		this->form->Deactivate();
	}
}
