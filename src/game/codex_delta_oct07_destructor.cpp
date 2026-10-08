#include <vector>
// NOTE: placeholder names and partial layouts for achievement-panel destruction at 0x7edd90.
struct DeltaConsoleBase { char pad[0x6c]; ~DeltaConsoleBase(); };
struct DeltaAchievementPanel : DeltaConsoleBase {
 std::vector<unsigned int> categories;
 int toggleAll;
 std::vector<unsigned int> unknown80;
 std::vector<unsigned int> unknown90;
 ~DeltaAchievementPanel();
};
DeltaAchievementPanel::~DeltaAchievementPanel() {}
