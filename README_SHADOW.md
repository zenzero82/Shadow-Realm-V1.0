# Shadow Pokemon
This repo implements Shadow Pokemon. It requires (and is built upon) the RHH Expansion.

## Preface
I'm still on hiatus from GBA dev in general (as of Feb. 2nd, 2023, when I'm writing this) but several people expressed interest in working on this project, so I cleaned it up a little and uploaded it to this repo. feel free to open issues and PRs/drafts for bugs and ideas. can't promise I'll be super active with checking them out, but I'm probably going to give Ed and maybe some others access to manage the repo and push things through.

this'll be a rough/messy readme for the time being, just getting some notes out there for those that are interested in contributing or anyone who's curious on how this generally works. this is long, but probably isn't complete - just an overview and some details on why certain changes exist. feel free to skip straight to the diff and come back here if you aren't sure what's going on

I can still be reached through Discord as well at Crater#7777 if you have specific questions, but I can't promise I'll have a ton of time to dedicate to larger requests/issues/etc.

## Tasks
some general things to work on/look into/think about:
- double battles likely still need some testing, and any nonstandard battle formats that RHH implements
- a toggle for the snag machine being acquired may be useful for some projects
- various EXP and level behavior - Rare Candy/EXP Candy immediately comes to mind, maybe EXP share as well. default battle EXP is already handled though
- friendship-related mechanics or interop with similar existing systems from vanilla/RHH
- in the same sense: mega evos, z-moves, and so on may work out of the box, but I think shadow mon should either be excluded until purification, or specific behavior could be implemented. for z-moves in particular, a Shadowium Z or something like that might be cool
- move teaching system (TMs, move tutor) needs restrictions for shadow mon
- a lot of the shadow moves in the gamecube games are just shadow-themed takes on existing moves. this concept should probably be extended to some of the more unique moves from newer generations, and some new concepts might be a good idea as well (one idea I had in particular was a shadow terrain move, but I didn't explore the concept beyond that)
- an effect/blend/etc. for shadow mon icons in the PC storage system, to tell at a glance? not sure how viable this would be, iirc that area of the game struggles with VRAM and such, but it'd be nice
- a better animation when a shadow mon is first identified during a battle (I think I currently use the poison anim as a placeholder, but it doesn't look that far off honestly)
- a system for easily creating "purification immune" pokemon in the style of Shadow Lugia would be nice, it'll probably require the purify chamber to be implemented though (see below)
- how do shadow mon/moves interact with contests? should they have new behavior outside of their moves?
- plenty of other things I probably forgot about, haven't thought of, or haven't tested thoroughly

additional tasks specific to certain topics are mixed in below

## Heart Gauge/Purification
the UI for this was a nightmare, but it works

the heart gauge has data implemented in and out of battle (more on the details of that below), along with a long list of UI changes to attempt to emulate the behavior in the gamecube games functionality is implemented for setting the initial/max value (i.e. Spheal in XD has a value of 1500) and it can also be modified in-battle with the proper animations

there's one major difference from the gamecube games in that it has 4 sections instead of 5

this is due to the way the healthbox sprite works, and also because symmetrically-sized pixel art and the 8x8 tile system don't play nicely with odd numbers of *anything*, really. as a result, the effects of each stage will differ a bit - some things will be merged from one section into others

todo:
- the purification code and sequence (should probably just copy a lot of stuff from the evolution scene, but who knows)
- the relic stone (should be super easy once the purification code is in place)
- heart gauge lowering items (incense, time flute, whatever else - maybe some new stuff based on newer game mechanics?)
- most of the heart gauge section unlock effects. I think I may have implemented EXP gain limitations that are stored until purification after a certain level, but I forget. pretty sure there's also a function I added for getting the current section. the rest is unimplemented atm but the groundwork is there
- there's an animation called `Special_SectionUnlock` I set up for when a new section of the heart gauge is unlocked. it's just a direct copy of the anim the EXP bar plays when a mon levels up, I didn't actually do anything with it yet other than that. it might not look great depending on what we can do with it, but figured it'd be neat to set up eventually

## Purify Chamber
this is more of a long-term goal, since it's probably going to be pretty difficult to pull off. there's very little completed on this so far. i have plans for a completely animated, custom-UI purification chamber with the mechanics being fairly close to the one in XD

so far I have a mockup of some of the UI elements and the general layout of things in Aseprite. the plan is to bastardize a lot of the PC storage UI elements (the cursor mechanics especially, as well as the mon icons, among other things), taking some animation code and such from things like the berry blender and maybe the casino games. but depending on what that looks like, it may be less *copying* and more *learning,* and then I'll just implement what I really want directly

additionally, I'd need to free up some saveblock space in order to store the mons inside it, just as the PC does most likely - either copying the method and using a new block of memory or using "ghost slots" in the existing box system that are inaccessible to the player. I'll end up needing space for 35 mons - while the gamecube games had 9 chambers, the UI layout I mocked up looks best with about 7, and each chamber holds 5 mon in it.

also considered using the PC directly, since the player would use that to place the mons in the chamber - so when they're placed, they could stay in the PC box they're in, but be placed in a sort of inaccessible "in-use" state until they're removed from the chamber.

## Moves
the ones from XD are added to the move list, but that's about it. will probably need to implement a shadow type as well as effectiveness tables, unless it'd be a better idea to use a different method to determine shadow move behavior

Kobe#7673 made some excellent progress on shadow moves though (including anims) and we planned to collaborate, so I expect we'll have those done sooner rather than later

## Hyper Mode/Reverse Mode

I plan on implementing reverse mode, but any Colosseum diehards could also implement hyper mode as well I guess, could have a config toggle or something like that

there's `isReverse` that's implemented in the `BoxPokemon` data (see below), as well as fully reciprocated through the battle controllers, but there's no functionality implemented yet in battles

## Call To Mon
basically, there's a new entry in `battle_message.h` called `gText_BattleMenuTrainer` that's used as a replacement for the battle actions. it just replaces "RUN" with "CALL" in every normal trainer battle, and performs heart gauge reduction (if the mon is shadow) as well as the accuracy boost that Pokemon XD introduced (if the mon isn't shadow). this also functions as a "turn pass" which is useful when dealing with certain situations in double battles while trying to catch a shadow pokemon from a trainer

just a quick note: `BattleScript_TrainerCallToMonShadow` calls `modifyheartvalue BS_ATTACKER, -1000`
this probably needs to be tweaked, -1000 was just a test value. it'll also need to be modified to only trigger when a mon is in reverse mode, instead of every time you call a shadow mon. see the reverse mode section below, there's a lot of work that needs done in this regard

todo:
- the above issue with the reduction script
- calling should wake sleeping mon, which I believe was a function in both gamecube games? (maybe add some config for this. I don't think it should be possible on the sleeping mon's turn since that'd nullify sleep moves entirely, which means it should only be possible in double battles)
- since wild shadow mon exist in system, it may be good to have a toggle for CALL/RUN in the battle menu. maybe something along the lines of pressing the select button to swap? open to other ideas

## BoxPokemon Data
this one's kinda big

there's 4 new fields in the `BoxPokemon` struct: `isShadow, `isReverse`, `heartValue`, and `heartMax`
but fear not: they take up no additional space! they also replace nothing! how, you may be asking?

***unions*** (don't call your HR manager!)

`NicknameShadowdata` is a union that's placed into the space where the nickname field used to be. since shadow pokemon can't have a nickname until they're purified (and at that point, they don't require shadow pokemon data) we can actually hotswap out the nickname for the shadow data without taking up any additional space. the nickname field was 10 bytes long (10 character limit) so that gives us quite a bit of space to work with. as it stands currently, `isReverse` is a u8 while `heartValue` and `heartMax` are both u16, so that leaves 5 additional unused bytes to play with, should this project (or any others that extend it) require it.

you may be asking, "what about `isShadow`?" and that's a great question! it's actually not in the union - it's in `PokemonSubstruct3`, as a bitfield - replacing `eventLegal`. there may be "cleaner" places to put this bitfield, but I think `eventLegal` won't be missed by many - it's useless. I removed or commented out all relevant functionality tied to the field, should be pretty clean.

you might also ask, "why not just put it in the nickname union? or use `heartMax` to determine if a mon is shadow or not?"

I found that it helps to have `isShadow` outside the union for checks, because if you call what'd normally be `isShadow` (or try to see if heartMax is 0, etc.) while it's in nickname mode, you're obviously going to get nickname characters instead. that, and it might be useful to keep it true after purification to determine whether a mon is a purified shadow mon or just a normal mon, since it loses all other shadow data post-purification

that said, I didn't start out with the above in mind. the nickname union idea was a clever idea suggested by (I think) MGriffin, and by that time I was actually using *more* of the substruct (the unused ribbons and such) to store my data. so feel free to use that as ammo against it, if you for some reason adore event-illegal mews. I'm open to using a different bitfield than `eventLegal` if someone feels really strongly about it, but I figured most of the "easier" bitfields are going to be the go-to for any other third party extensions that require the space. so I can avoid potential conflicts with them by using a more code-ingrained one while also (presumably) not actually breaking any vanilla behavior

todo:
- any code that changes nicknames may be prone to bugs, but I think I caught a lot of that behavior at the accessor functions already. dialgoue for things like that (name rater) may need some conditions and strings to handle it properly though.

## Graphics
modifications were made to a few graphics, namely ball_status_bar.png and expbar.png
I honestly don't remember exactly what I did, but I believe I swapped the palettes around a bit. might have implemented colors for otherwise unused values so I could use them elsewhere

some actual additions were made to the `summary_screen` tileset in previously blank/unused areas, and it also has a dedicated palette now. these changes facilitate the replacement of the EXP bar graphics with the heart gauge counterpart

### Healthbox Split
basically, the vanilla healthbox uses the same palette tag for all 4 healthboxes. undoing this took a lot of lot of time, and I ended up having to track down a lot of bugs regarding this stuff, but it should be fully stable and functional now.

I say "all 4" because this is set up for double battles as well - if a mon is shadow, it'll set its healthbox palette to a different color. if it's the player's mon in a single battle, the healthbox changes drastically, with the EXP bar replaced with the Heart Gauge and so on. it works pretty nicely, I tested a lot of cases but I could have missed some - I didn't go far beyond normal single and double battles

## Trainers & Testing
in trainers.h there's `F_TRAINER_PARTY_SHADOW_TEST`. this ties in with `TrainerMonNoItemDefaultMovesShadow`, which was the only type I implemented so far. there should probably be shadow versions of all the vanilla constructors eventually, to allow custom moves/items/etc. but basically, it just passes in whether or not a given mon in the trainer party is shadow, and what the starting heart gauge value/max should be. the heart gauge value passed in should probably be evenly divisible by 100 like the gamecube games handle it, but it's not enforced by code (nor should it be, I guess - go wild)

i defined a test trainer, `TRAINER_SHADOW_TEST`, which should probably be removed before a real release or whatever. it corresponds with the `sParty_ShadowTest` trainer party

this stuff could use some polish and expansion, or at least a rename of some of the current things that have "test" in the name that are actually generic and usable

also here's a very basic test script for wild shadow mon:
```lockall
setwildshadowbattle SPECIES_ZIGZAGOON, 10, 0, 1000
dowildbattle
releaseall```

=================ZENZERO82=======================

---

## Shadow Realm V1.0 Fork – Additional Changes

This fork is based on AsparagusEduardo’s Shadow Pokémon PR (#4128) for pokeemerald-expansion.  
All notes above this section belong to the original authors. The sections below document **fork-specific changes**.

### High-level features added in this fork

- **Heart Gauge backend integration**
  - Added heart value/max value to party → battle conversion so the gauge is available in-battle.
  - Implemented `GetMonHeartValue` / `GetMonHeartMax` helpers hooked into `PokemonToBattleMon`.
  - Shadow Pokémon caught via Snag now start with **full Heart Gauge** (e.g. 5000) for testing.

- **Heart Gauge behavior in battle**
  - Implemented a new `VARIOUS_MODIFY_HEART_VALUE` case so that **Call** reduces the Heart Gauge.
  - After a successful Call, the heart value is updated on the Pokémon and the Shadow HUD is synced.
  - Shadow string `"PKMN's heart gauge fell!"` (or equivalent) is shown when the gauge changes.
  - Currently the visual shadow bar fully refreshes when opening/closing a menu (bag/party); live animation refresh is WIP.

- **Shadow HUD / healthbox integration**
  - Added `ShadowHud_RefreshHeartGauge` to re-sync the gauge to the underlying heart value.
  - Hooked Shadow HUD clear/sync into ball throw and faint logic so snagged shadows clear their HUD state correctly.

- **Reverse Mode & aggression by nature**
  - Implemented an aggression value derived from **nature**; higher aggression increases the chance to enter Reverse Mode.
  - Auto-enter Reverse Mode when the internal “fever pitch” condition triggers (instead of only doing visuals).
  - Once Called, the mon leaves Reverse Mode, and it can re-enter only via the normal random rolls.
  - Known quirk: some high-aggro shadows may still start in Reverse Mode – to be tuned later.

- **Purification ready flag**
  - At the end of battle / return to field, the game scans the player’s party for shadows with **empty Heart Gauge**.
  - If any are ready, it sets a new flag and runs a global event script (no per-map scripting needed) to show a message like  
    “A Pokémon is ready to open the door to its heart!”
  - This is a temporary implementation pending full purification flow + animations.

- **Trainer shadow ownership / rematch scaffolding**
  - Added helper logic to determine whether a **trainer still owns an unsnagged Shadow Pokémon**, using:
    - Shadow IDs on trainer party entries.
    - `PlayerOwnsShadowId(shadowId)` to scan all player storage and ensure the mon was actually snagged.
  - Created temporary helper(s) to allow:
    - Re-battling a trainer that still has an unsnagged Shadow.
    - Treating trainers as “cleared” once all of their shadow IDs are in the player’s possession.
  - Long-term plan: replace this with a proper “Shadow Monitor” / Pokédex upgrade that tracks shadows globally and swaps defeated / unsnagged shadows out of trainer parties.

### Files touched in this fork (summary)

> **Note:** This is *only* a summary of additional fork changes, not a full diff vs. pokeemerald-expansion.

- `include/pokemon.h`
  - Added function prototypes for heart gauge accessors and shadow-related helpers.
- `src/pokemon.c`
  - Implemented heart gauge getters.
  - Added `PlayerOwnsShadowId` for scan across party/boxes for a given Shadow ID.
- `include/battle_interface.h`
  - Declared Shadow HUD helper functions.
- `src/battle_interface.c`
  - Implemented `ShadowHud_RefreshHeartGauge` and related HUD wiring.
- `src/battle_script_commands.c`
  - Extended `Cmd_various` with a `VARIOUS_MODIFY_HEART_VALUE` handler for the Call action.
- `src/battle_main.c`
  - Snag logic: mark trainer’s shadow as snagged, zero HP, clear healthbox & HUD.
  - Added Trainer/Shadow helper routines (unsnagged check, etc.).
  - Integrated aggression-based Reverse Mode behavior.
- `src/overworld.c`
  - Hooked into `CB2_ReturnToFieldContinueScriptPlayMapMusic` to trigger the global “purification ready” event script if any party shadow is fully opened.
- `src/script_pokemon_util.c`
  - Added native script function(s) to expose “trainer has unsnagged shadow” logic to events.
- `data/event_scripts.s` / `data/maps/.../scripts.inc`
  - Added temporary global event script and a test trainer behavior for shadow rematches.

### Known issues / TODO

- Live animation of the Heart Gauge bar during Call is still flaky; currently reliable after opening a menu.
- Shadow trainer rematch rules are temporary; trainers aren’t yet auto-rebalanced with replacement non-shadow mons.
- Full purification flow (animation, location logic, move learning, ribbon, etc.) still to be implemented.
- Some high-aggression shadows may enter Reverse Mode at battle start more often than intended.

---

_Last updated: 2025-11-21._
