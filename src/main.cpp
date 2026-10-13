#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

// Hook that keeps the editor's "Free Move" mode forced on while the mod is
// enabled. In Free Move mode GD moves selected objects by the exact touch
// delta instead of snapping them to the grid, on both the X and Y axes.
class $modify(NoRoundingEditorUI, EditorUI) {
	void forceFreeMove() {
		if (Mod::get()->getSettingValue<bool>("enabled")) {
			m_freeMoveEnabled = true;
		}
	}

	bool ccTouchBegan(CCTouch* touch, CCEvent* event) {
		forceFreeMove();
		return EditorUI::ccTouchBegan(touch, event);
	}

	void ccTouchMoved(CCTouch* touch, CCEvent* event) {
		forceFreeMove();
		EditorUI::ccTouchMoved(touch, event);
	}
};
