# MapType descriptor alias correction

The retail getter at `0x4dbda0` calls `0x4dbce0` and loads the pointer at `0xceca88`. The assignment helper at `0x4dbc40` passes the enum array at `0xceca80` and the message metadata array at `0xcecab0` to protobuf's descriptor assignment routine. The getter therefore reads enum slot 2.

The serialized retail FileDescriptorProto, referenced by `0x4dbd20` at `0xc1baf8` with length `0x12e03`, identifies slot 2 as MapType. Its enum order agrees with the generated source: DifficultyType, SpecialModeType, MapType, HeatLevelType, MoveModeType, UiLayoutType, MovementInputType, FullscreenType, SteamType, SchematicType, SchematicMethodType, StudyMethodType. Retail callers use MAP_ names when looking up enum values.

`config/mapping.d/lead_discovered.csv` previously assigned 210 descriptor names to this one getter: 198 message getters and 12 enum getters. The corrected mapping retains only MapType and removes the other 209 aliases. Equal values in zero-initialized descriptor tables did not establish getter identity; the other real bodies have not been located by this audit.

The cleanup also registers the existing assignment and AddDescriptorsImpl helpers. No schema, implementation, verifier, or function-index changes are required. The combined gate and registration-order verification both pass: `build/manager_loop_descriptor_gate_01.log` and `build/manager_loop_descriptor_registered_01.log`. The candidate stub audit reports zero accesses at nonzero offsets within 4 KiB generated stub slots.

Detailed extraction, raw getter bytes, exact excluded names, table pairings, and isolated proofs remain in the private local scratch area `scratch/loop_alpha_02/`. Game-function counts count addresses once, so removing these aliases does not remove a matched function. These are static reconstruction checks, not runtime descriptor initialization tests.
