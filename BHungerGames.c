//
//  BHSimulator.c
//  BH Simulator
//
//  Created by Cesar Salad Jaimes on 20/04/2017.
//  Copyright � 2017 Cesar Salad Jaimes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "BHSimulator.h"

int scenarioDelay[81] = {0};

void Scenarios(char name[20], char nameA[20], char nameB[20], int player) {

	bool scenarioSelected = false;
	while (!scenarioSelected) {
		int a = rand() % 83;
		if (a == 0 && player > 2 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s made an alliance with %s to kill %s. But %s shouldn't have trusted %s... %s has killed %s.\n\n", name, nameA, nameB, name, nameA, nameA, name);
		}
		else if (a == 1 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s stepped on a mine. What a shame.\n\n", name);
		}
		else if (a == 2 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s is extremely hungry. He hasn't eaten for days. He sees %s eating some berries in the forest but %s drops dead. ''I wonder what human flesh tastes like!'' tells %s to himself.\n\n", nameA, name, name, nameA);
		}
		else if (a == 3 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s got mauled by genetically modified Korgz.\n\n", name);
		}
		else if (a == 4 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s died of a wound infection inflicted by %s whilst fighting for some ressources.\n\n", name, nameA);
		}
		else if (a == 5 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("A giant rock fell on %s's head... But how?\n\n", name);
		}
		else if (a == 6 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("It's a miracle! %s escaped from the deadly Nosdoodoo! Oh wait! Never mind, %s just got eaten by Blubber...\n\n", name, name);
		}
		else if (a == 7 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Taters has muted %s once and for all.\n\n", name);
		}
		else if (a == 8 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Oh no! %s has just bet his life with Grimz! And he lost :( .\n\n", name);
		}
		else if (a == 9 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s died of sodium chloride overdose.\n\n", name);
		}
		else if (a == 10 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s has just seen RNGesus in front of him! He asks him if he can win and to that question, RNGesus responds:'nope'. %s dies.\n\n", name, name);
		}
		else if (a == 11 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("What people don't know is that Mimziy is very territorial... Oh look! %s has stepped into his territory! Bye bye %s.\n\n", name, name);
		}
		else if (a == 12 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s broke his ankle. Is that a Zorg I see rushing towards %s? Yes, yes it is.\n\n", name, name);
		}
		else if (a == 13 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s finds some food on the ground! Great news.... for %s that was waiting for him.  %s kills %s. \n\n", name, nameA, nameA, name);
		}
		else if (a == 14 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s is steadily aiming his arrow to %s, drinking water from the river. *woosh* Bullseye\n\n", nameA, name);
		}
		else if (a == 15 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("A wild Kov' Arg appears!'Death or snusnu ? '.'Death' replies %s.'Farewell... Death....By snusnu!'\n\n", name);
		}
		else if (a == 16 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s encounters Warty.Warty tells him to kiss him so he could transform into a beautiful princess. %s is way too naive! As soon as %s kisses Warty, his poison consumes him into a pile of goo...\n\n", name, name, name);
		}
		else if (a == 17 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s just died\n.\n.\n.\n.\n jk!\n %s died in his place.Ha.", nameA, name);
		}
		else if (a == 18 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s spent all his gems on large eggs and got nothing... %s committed suicide\n\n", name, name);
		}
		else if (a == 19 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s sees a big footprint on the ground.It looks like a yeti's footprint ? Yup.Yeti just ate %s.\n\n", name, name);
		}
		else if (a == 20 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s found the one ring to rule them all!He will posses incredible power!Watch out!A Golum is charging at you!Too late : (\n\n", name);
		}
		else if (a == 21 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s is allergic to peanuts.He was unaware of it and just ate some that %s gave him... Coincidence ? I think not!\n\n", name, nameA);
		}
		else if (a == 22 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s disconnected in the middle of Kaleido heroic fight... : rip:\n\n", name);
		}
		else if (a == 23 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s decided to go hunt for food. %s shoots his arrow - but whats this? the arrow ricochets and unfortunately hits %s in the knee... Damn RNG!", name, name, name);
		}
		else if (a == 23 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s dies as a result of shaving. %s was unaware that %s had dipped his shaving knife in a poisonous mixture... \n\n", name, name, nameA);
		}
		else if (a == 24 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("The powerful wizard %s is on the run and accidentally trips over his own beard, falling to his death.. \n\n", name);
		}
		else if (a == 25 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Gobby loves stealing from people.He just stole all of %s's money... %s died of depression.\n\n", name, name);
		}
		else if (a == 26 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s just broke Olxaroth's card castle! Filled with anger, Olxaroth's reduces %s in a pile of ashes. /n/n", name, name);
		}
		else if (a == 27 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s is smart, and decides to hide up in the trees. \n Could this be it? is it? YES! - its time to drop the blubber suit and turn into a buuutiful butterfly! Unfortunately, fairytales are not real, and %s didnt fly, but fell to his death \n\n", name, name);
		}
		else if (a == 28 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s thought it would be wise to bring a stick to a sword fight... %s dies.. \n\n", name, name);
		}
		else if (a == 29 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Everyone hate Mimeido. %s agrees to this statement.But %s forgot Mimeido could oneshot him : ) \n\n", name, name);
		}
		else if (a == 30 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s is sneaking around the castle, when suddenly he runs into Gemmroid! 'Do you even lift bro?' - says Gemmroid. Filled with shame and un-impressive gains %s must forfeit.. \n\n", name, name);
		}
		else if (a == 31 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s is walking along side a cliff and slips!He catches the edge. %s sees all the action, approaches %s and flips a coin.'heads, you live'.It's tails : / \n\n", name, nameA, name);
		}
		else if (a == 32 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("The gamemakers send in a swarm of Melvinsteins to disrupt the game! While attempting to run from them, %s tripped and fell, allowing the Melvinsteins to eat him alive. \n\n", name);
		}
		else if (a == 33 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s makes a run for the remaining items in the Cornucopia! Little did %s know that %s was waiting with an enormous Glimmer, ready to decapitate. %s 's head  \n\n", name, name, nameA, name);
		}
		else if (a == 34 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Knowing %s cannot survive alone, %s sends out a friend request: 'lvl 6 looking for lvl 250+ to help me complete r2 heroic!' %s 's request is denied, and promptly dies without an alliance. \n\n", name, name, name);
		}
		else if (a == 35 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("As %s runs through a dungeon, %s spies a Mimeido! But he didn't watch all his items and Mimeido ate his foot pretending to be a sock. \n\n", name, name);
		}
		else if (a == 36 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s was foraging for food when they spotted a wild Shrump! Unfortunately, %s voted for Nyxn in the last Bit Heroes election, and when Shrump heard about that, he banished %s for life. \n\n", name, name, name);
		}
		else if (a == 37 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s was doing just fine up until they proposed that Bit Heroes should have more fan fiction. Tarri disagreed, and laid down the banhammer. \n\n", name);
		}
		else if (a == 38 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Krusty always wanted to open the Krusty Krab....And he's pretty sad about it... For that reason, he crits %s for no reason.\n\n", name);
		}
		else if (a == 39 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s runs into a wild gang of Pengeys. Shaking with fear and regret of the paths taken, %s decides to make a run for it... \n %s underestimated the powers of this wild gang, and quickly realises, he dun goof'd \n\n", name, name, name);
		}
		else if (a == 40 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s didn't believe Wemmbo crit chance was high enough to worry about... Boy was he wrong\n\n", name);
		}
		else if (a == 41 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s didn't use CAPS in Salt_mines. Byleth bans him forever!\n\n", name);
		}
		else if (a == 42 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s and %s teamed up in an alliance, but in a cruel twist of fate, %s broke that alliance and pushed %s off a cliff. \n\n", name, nameA, nameA, name);
		}
		else if (a == 43 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("After hours of searching, %s has found a pool from which to drink! . . . but it turns out to be a pool of Kaleido's tears. %s is banished to R2 never to return. \n\n", name, name);
		}
		else if (a == 44 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s and %s have found a Gemmroid! He challenges both of them to leg day. Sadly, %s gets rhabdomyalysis and dies. \n\n", name, nameA, name);
		}
		else if (a == 45 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s finds a rare candy on the ground! But it turns out to be ground candy. %s vomits the entire contents of his stomach and dies of malnutrition. \n\n", name, name);
		}
		else if (a == 46 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s ventures into world chat! Oh no! He is too high of a level and is spammed to death. \n\n", name);
		}
		else if (a == 47 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("'Want to hear a joke?' Warty said to %s. %s said no, so Warty ate him. \n\n", name, name);
		}
		else if (a == 48 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Walking up the mountain of Lost Heroes, %s encountered Vedic! Vedic draws and quarters %s with his samurai sword. \n\n", name, name);
		}
		else if (a == 49 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Without skipping a beat, %s hides, as he can hear footsteps closing in... \n%s sneaks up on %s... %s dies. \n\n", name, nameA, name, name);
		}
		else if (a == 50 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("While on the hunt for some delicious booty, %s unfortunately becomes the prey to the ferocious Dina.. \n\n", name);
		}
		else if (a == 51 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s attempts to beat Blasian in an Astaroth Flag pvp tournament! %s runs out of time, money, points, and sanity. \n\n", name, name);
		}
		else if (a == 52 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s sees a [K] member. OMG! Unfortunately, the [K] member doesn't have times and kills %s.\n\n", name, name);
		}
		else if (a == 53 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s pulls a Leeroy Jenkins and rushes into z4d4. We all know how that turns out. \n\n", name);
		}
		else if (a == 54 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Covered in dirt, and tired from battle %s decides that its time to take a swim in the nearby lake. %s forgot he couldnt swim.. rip \n\n", name, name);
		}
		else if (a == 55 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s dies.Like, nothing happened to him, he just collapsed like a pile of shit. : / \n\n", name);
		}
		else if (a == 56 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s makes the mistake of eating Yeti's Frozen Spaghetti and is frozen from the inside out. \n\n", name);
		}
		else if (a == 57 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s sees a mysterious shadow near the horizon.Who could it be ? Nanananananananana, Bubbo! And he's here to wreck %s's booty!\n\n", name, name);
		}
		else if (a == 58 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s attempts to talk to Quinn one times too many. Didn't you get the hint the 54th time you asked? \n\n", name);
		}
		else if (a == 59 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s quipped mirror wings and astaroth armor, got mistaken by Warty as a fly. %s died due to digestive chemicals...\n\n", name, name);
		}
		else if (a == 60 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s and %s have been walking all day. Very tired, they both decide to have a quick picnic. Unfortunately a swarm of Terrumps covered the sky dark and went in for the kill.. \n %s managed to get away, but %s wasnt so lucky.. \n\n", name, nameA, nameA, name);
		}
        else if (a == 61 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s was offline for 2 days and all his high level friends removed him. %s didn't notice and did R2 Heroic anyways. \n\n", name, name);
        }
        else if (a == 62 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s DC'ed from the game and lost 5 gauntlet tokens. And his life. \n\n", name);
         }
        else if (a == 63 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s has found the legendary Juppiomenz in a gauntlet! Too bad he was the only player left on his team. \n\n", name);
        }
        else if (a == 64 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s Has been declined by one too many familiars! \n\n", name);
        }
        else if (a == 65 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s Fell off a cliff playing Pokemon GO \n\n", name);
        }
        else if (a == 66 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s put on some major speed kicks and ran fast... directly off a cliff. \n\n", name);
        }
        else if (a == 67 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s Found the legendary Tobey and challenged him to a duel! Big mistake. \n\n", name);
        }
        else if (a == 68 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s has drowned in a sea of duel requests. \n\n", name);
        }
        else if (a == 69 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s accidentally clicked R2 heroic instead of R2 normal. Whoops! \n\n", name);
        }
        else if (a == 70 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s has died of dysentary. \n\n", name);
        }
        else if (a == 71 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s Died of exhaustion trying to find the Bobodom schematic for 6 straight weeks. \n\n", name);
        }
        else if (a == 72 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s heard SSS1 speak, and therefore SSS1 had to kill %s. \n\n", name, name);
        }
        else if (a == 73 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s didn't celebrate Blubber Day, and Blubber got mad and ate him. \n\n", name);
        }
        else if (a == 74 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s attacked Rolace! Rolace deflected %s's attack right into %s and killed him. \n\n", name, name, name);
        }
        else if (a == 75 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s was wandering around and saw a crazy Encon searching for schematics. He tried to duel him, but Encon used pocket salt, %s went blind and died to a Bubbo crit", name, name);
        }
        else if (a == 76 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s sees a Blubbicorn! Rumours say they have 0.000000001%% of spawning in the game! They're also ridiculously strong... %s got rekt by Blubbicorn's Impale!", name, name);
        }
        else if (a == 77 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s sneezed.\nHis sneeze scared the shit out of Mr. Bob who then proceeded to kill %s who happened to walk by.", nameA, name);
        }
        else if (a == 78 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s stabbed %s and ran away like a rascal that he is.", nameA, name);
        }
        else if (a == 79 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s played Blackjack with Quinn. Quinn didn't want to play and left. %s died of solitude.", name, name);
        }
        else if (a == 80 && scenarioDelay[a] == 0) {
            scenarioDelay[a] += 20;
            scenarioSelected = true;
            printf("%s stabs his eyes and falls off a cliff. Happy?", name);
        }
		else if (a == 81 && scenarioDelay[a] == 0) {
			scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("Never feed a Nelson past midnight... Rookie error %s...", name);
		}
		else if (a == 82 && scenarioDelay[a] == 0) {
			scenarioDelay[a] += 20;
			scenarioSelected = true;
			printf("%s sadly finds nemo. It wasn't the fish though... RIP %s", name, name);
		}
    }


}

void BHungerGames() {
	//
	int participants = 200;
	int t;
	typedef struct BHG {
		char name[20];
		float chance;
		bool result;
		bool alive;
	} Contestants;

	Contestants contestants[200];

	strcpy(contestants[0].name, "Ryansdryan");
	strcpy(contestants[1].name, "ACphoenix");
	strcpy(contestants[2].name, "Nyuki");
	strcpy(contestants[3].name, "ToxicBuilt");
	strcpy(contestants[4].name, "Krishy81");
	strcpy(contestants[5].name, "CrushedPhantasm8");
	strcpy(contestants[6].name, "Grindar");
	strcpy(contestants[7].name, "Noktuk");
	strcpy(contestants[8].name, "kyfo");
	strcpy(contestants[9].name, "N3RFED");
	strcpy(contestants[10].name, "MeatSuit");
	strcpy(contestants[11].name, "Cavi2284");
	strcpy(contestants[12].name, "LG1T XI");
	strcpy(contestants[13].name, "Hermes");
	strcpy(contestants[14].name, "Mallick");
	strcpy(contestants[15].name, "Wateryhoitytoity");
	strcpy(contestants[16].name, "KKyoji");
	strcpy(contestants[17].name, "Rydarion");
	strcpy(contestants[18].name, "Fuzzyworth");
	strcpy(contestants[19].name, "Kanwal22");
	strcpy(contestants[20].name, "Krealor");
	strcpy(contestants[21].name, "Taphos");
	strcpy(contestants[22].name, "aFFy");
	strcpy(contestants[23].name, "Bubs");
	strcpy(contestants[24].name, "Elemental");
	strcpy(contestants[25].name, "RedRidingHoodie");
	strcpy(contestants[26].name, "Phlux");
	strcpy(contestants[27].name, "RendingHavoc");
	strcpy(contestants[28].name, "Sinnar");
	strcpy(contestants[29].name, "Hai");
	strcpy(contestants[30].name, "Dadam137");
	strcpy(contestants[31].name, "Halsover");
	strcpy(contestants[32].name, "VaporBrother");
	strcpy(contestants[33].name, "Aimac");
	strcpy(contestants[34].name, "Qwipgar");
	strcpy(contestants[35].name, "Cestus");
	strcpy(contestants[36].name, "Trakomo");
	strcpy(contestants[37].name, "Tajier");
	strcpy(contestants[38].name, "Zxcasdqwe");
	strcpy(contestants[39].name, "BrioBlu");
	strcpy(contestants[40].name, "schnock");
	strcpy(contestants[41].name, "warahyuu");
	strcpy(contestants[42].name, "LeonYuu");
	strcpy(contestants[43].name, "Bhekk");
	strcpy(contestants[44].name, "DashAhead");
	strcpy(contestants[45].name, "Kiwuy");
	strcpy(contestants[46].name, "LOXMATblY");
	strcpy(contestants[47].name, "Hustin");
	strcpy(contestants[48].name, "Anton6666");
	strcpy(contestants[49].name, "Snuffles213");
	strcpy(contestants[50].name, "HidetoBandou");
	strcpy(contestants[51].name, "Pyro");
	strcpy(contestants[52].name, "Grindalwald");
	strcpy(contestants[53].name, "Hermes");
	strcpy(contestants[54].name, "Tsunatsu");
	strcpy(contestants[55].name, "Geugen14");
	strcpy(contestants[56].name, "Living Pillow");
	strcpy(contestants[57].name, "phear");
	strcpy(contestants[58].name, "derrkkk");
	strcpy(contestants[59].name, "Pettirosso - lvl 92");
	strcpy(contestants[60].name, "Kimnak");
	strcpy(contestants[61].name, "LG1T");
	strcpy(contestants[62].name, "Aerid");
	strcpy(contestants[63].name, "Ardazafer");
	strcpy(contestants[64].name, "DoktaR");
	strcpy(contestants[65].name, "Recab");
	strcpy(contestants[66].name, "Encon");
	strcpy(contestants[67].name, "Kempha");
	strcpy(contestants[68].name, "Bosshog732");
	strcpy(contestants[69].name, "tonytyzhang");
	strcpy(contestants[70].name, "co_giy");
	strcpy(contestants[71].name, "MGEKO");
	strcpy(contestants[72].name, "McCluckle");
	strcpy(contestants[73].name, "kanonbaal");
	strcpy(contestants[74].name, "Moqcev");
	strcpy(contestants[75].name, "SoulCrusherE");
	strcpy(contestants[76].name, "Taters");
	strcpy(contestants[77].name, "Forch");
	strcpy(contestants[78].name, "alchemie");
	strcpy(contestants[79].name, "ThingBlue");
	strcpy(contestants[80].name, "Zayu");
	strcpy(contestants[81].name, "greendia");
	strcpy(contestants[82].name, "xionicmadness");
	strcpy(contestants[83].name, "Azderon");
	strcpy(contestants[84].name, "SinOfPride");
	strcpy(contestants[85].name, "Blupapi");
	strcpy(contestants[86].name, "TheNamelessGod");
	strcpy(contestants[87].name, "Fresshness");
	strcpy(contestants[88].name, "minuminu");
	strcpy(contestants[89].name, "Zlexar");
	strcpy(contestants[90].name, "Nikkitine");
	strcpy(contestants[91].name, "12sPaWn12");
	strcpy(contestants[92].name, "mnaitzme12");
	strcpy(contestants[93].name, "Hiibye");
	strcpy(contestants[94].name, "ikillforblood69");
	strcpy(contestants[95].name, "Phreakaz0id");
	strcpy(contestants[96].name, "PancakeJuice");
	strcpy(contestants[97].name, "ChiefPlasma24");
	strcpy(contestants[98].name, "16ind");
	strcpy(contestants[99].name, "Labelle");
	strcpy(contestants[100].name, "Yozu");
	strcpy(contestants[101].name, "VileTitan");
	strcpy(contestants[102].name, "God");
	strcpy(contestants[103].name, "jooe15");
	strcpy(contestants[104].name, "Fipps");
	strcpy(contestants[105].name, "BlitzXKrieg");
	strcpy(contestants[106].name, "ZeroCrash");
	strcpy(contestants[107].name, "Jaocy");
	strcpy(contestants[108].name, "HadesDps");
	strcpy(contestants[109].name, "Kalam101");
	strcpy(contestants[110].name, "UPhagocytosis");
	strcpy(contestants[111].name, "Prism0");
	strcpy(contestants[112].name, "MartyMcFly");
	strcpy(contestants[113].name, "JBz");
	strcpy(contestants[114].name, "lnoN");
	strcpy(contestants[115].name, "Shinjifo");
	strcpy(contestants[116].name, "Duydesbois");
	strcpy(contestants[117].name, "nickzncs");
	strcpy(contestants[118].name, "Esoum");
	strcpy(contestants[119].name, "icoter");
	strcpy(contestants[120].name, "Davyluiz");
	strcpy(contestants[121].name, "Kaboomafoo");
	strcpy(contestants[122].name, "Thailoo");
	strcpy(contestants[123].name, "Ardazafer");
	strcpy(contestants[124].name, "ishotboston");
	strcpy(contestants[125].name, "Gegil");
	strcpy(contestants[126].name, "Nazuya");
	strcpy(contestants[127].name, "TiffyTiff");
	strcpy(contestants[128].name, "Softy");
	strcpy(contestants[129].name, "Atakus");
	strcpy(contestants[130].name, "MadHatterMike");
	strcpy(contestants[131].name, "KamiSaric");
	strcpy(contestants[132].name, "GUIMAS");
	strcpy(contestants[133].name, "Velkrath");
	strcpy(contestants[134].name, "CJFLOW");
	strcpy(contestants[135].name, "KUSmurf");
	strcpy(contestants[136].name, "naagok");
	strcpy(contestants[137].name, "LazyGenius");
	strcpy(contestants[138].name, "Tvan1016");
	strcpy(contestants[139].name, "peroguy");
	strcpy(contestants[140].name, "richiss");
	strcpy(contestants[141].name, "Deucey");
	strcpy(contestants[142].name, "Kaalia");
	strcpy(contestants[143].name, "FabsBorlotto");
	strcpy(contestants[144].name, "Ballardz ");
	strcpy(contestants[145].name, "mikeyje");
	strcpy(contestants[146].name, "xDAZx");
	strcpy(contestants[147].name, "DeadlyNinja123");
	strcpy(contestants[148].name, "deathreaver198");
	strcpy(contestants[149].name, "StrikerNZ");
    strcpy(contestants[150].name, "HidetoBandou");
    strcpy(contestants[151].name, "Pyro");
    strcpy(contestants[152].name, "Grindalwald");
    strcpy(contestants[153].name, "Hermes");
    strcpy(contestants[154].name, "Tsunatsu");
    strcpy(contestants[155].name, "Geugen14");
    strcpy(contestants[156].name, "Living Pillow");
    strcpy(contestants[157].name, "phear");
    strcpy(contestants[158].name, "derrkkk");
    strcpy(contestants[159].name, "Pettirosso - lvl 92");
    strcpy(contestants[160].name, "Kimnak");
    strcpy(contestants[161].name, "LG1T");
    strcpy(contestants[162].name, "Aerid");
    strcpy(contestants[163].name, "Ardazafer");
    strcpy(contestants[164].name, "DoktaR");
    strcpy(contestants[165].name, "Recab");
    strcpy(contestants[166].name, "Encon");
    strcpy(contestants[167].name, "Kempha");
    strcpy(contestants[168].name, "Bosshog732");
    strcpy(contestants[169].name, "tonytyzhang");
    strcpy(contestants[170].name, "co_giy");
    strcpy(contestants[171].name, "MGEKO");
    strcpy(contestants[172].name, "McCluckle");
    strcpy(contestants[173].name, "kanonbaal");
    strcpy(contestants[174].name, "Moqcev");
    strcpy(contestants[175].name, "SoulCrusherE");
    strcpy(contestants[176].name, "Taters");
    strcpy(contestants[177].name, "Forch");
    strcpy(contestants[178].name, "alchemie");
    strcpy(contestants[179].name, "ThingBlue");
    strcpy(contestants[180].name, "Zayu");
    strcpy(contestants[181].name, "greendia");
    strcpy(contestants[182].name, "xionicmadness");
    strcpy(contestants[183].name, "Azderon");
    strcpy(contestants[184].name, "SinOfPride");
    strcpy(contestants[185].name, "Blupapi");
    strcpy(contestants[186].name, "TheNamelessGod");
    strcpy(contestants[187].name, "Fresshness");
    strcpy(contestants[188].name, "minuminu");
    strcpy(contestants[189].name, "Zlexar");
    strcpy(contestants[190].name, "Nikkitine");
    strcpy(contestants[191].name, "12sPaWn12");
    strcpy(contestants[192].name, "mnaitzme12");
    strcpy(contestants[193].name, "Hiibye");
    strcpy(contestants[194].name, "ikillforblood69");
    strcpy(contestants[195].name, "Phreakaz0id");
    strcpy(contestants[196].name, "PancakeJuice");
    strcpy(contestants[197].name, "ChiefPlasma24");
    strcpy(contestants[198].name, "16ind");
    strcpy(contestants[199].name, "Labelle");

	for (t = 0; t < participants; t++) {
		contestants[t].chance = 90;
	}

	/*contestants[0].chance = 90;
	contestants[1].chance = 90;
	contestants[2].chance = 90;
	contestants[3].chance = 90;
	contestants[4].chance = 90;
	contestants[5].chance = 90;
	contestants[6].chance = 90;
	contestants[7].chance = 90;
	contestants[8].chance = 90;
	contestants[9].chance = 90;
	contestants[10].chance = 90;
	contestants[11].chance = 90;
	contestants[12].chance = 90;
	contestants[13].chance = 90;
	contestants[14].chance = 90;
	//	contestants[15].chance = 90;
	//	contestants[16].chance = 90;
	//	contestants[17].chance = 90;
	//contestants[18].chance = 90;
	//contestants[19].chance = 90;*/

	for (t = 0; t < participants; t++) {
		contestants[t].alive = true;
	}
	/*contestants[0].alive = true;
	contestants[1].alive = true;
	contestants[2].alive = true;
	contestants[3].alive = true;
	contestants[4].alive = true;
	contestants[5].alive = true;
	contestants[6].alive = true;
	contestants[7].alive = true;
	contestants[8].alive = true;
	contestants[9].alive = true;
	contestants[10].alive = true;
	contestants[11].alive = true;
	contestants[12].alive = true;
	contestants[13].alive = true;
	contestants[14].alive = true;
	//	contestants[15].alive = true;
	//	contestants[16].alive = true;
	//	contestants[17].alive = true;
	//	contestants[18].alive = true;
	//contestants[19].alive = true;*/



	//contestants[0].alive = false;
	//contestants[1].alive = false;
	//contestants[2].alive = false;
	//contestants[3].alive = false;
	//contestants[4].alive = false;
	//contestants[5].alive = false;
	//contestants[6].alive = false;
	//contestants[7].alive = false;
	//contestants[8].alive = false;
	//contestants[9].alive = false;
	//contestants[10].alive = false;
	//contestants[11].alive = false;
	//contestants[12].alive = false;
	//contestants[13].alive = false;
	//contestants[14].alive = false;

	int night = 0;
	int morningcount = 0;
	int j;
    int delayc;
	int playerAlive = 0;
	for (j = 0; j < participants; j++) {
		if (contestants[j].alive) {
			playerAlive++;
		}
	}
	int i;
	int a = 0, b = 0;
	while (playerAlive > 3) {  /// :)r
		morningcount = playerAlive;
		if (night % 7 == 0) {
			printf("\n\n**Players remaining: %d**\n\n", playerAlive);
		}
		night++;
		printf("\nNight %d:\n\n", night);
		for (i = 0; i < participants; i++) {
			if (contestants[i].alive) {
				contestants[i].result = RNGroll(contestants[i].chance);
				if (!contestants[i].result) {
					playerAlive--;
					contestants[i].alive = false;
					bool target1 = false, target2 = false;
					while (!target1) {
						a = rand() % participants;
						if (contestants[a].alive) {
							target1 = true;
						}
					}
					while (!target2 && playerAlive > 1) {
						b = rand() % participants;
						if (contestants[b].alive && a != b) {
							target2 = true;
						}
					}

					Scenarios(contestants[i].name, contestants[a].name, contestants[b].name, playerAlive);
                    for (delayc = 0; delayc < 81 ; delayc++){
                        if (scenarioDelay[delayc] !=0){
                            scenarioDelay[delayc]--;
                        }
                    }
				}
			}
		}
		if (playerAlive == morningcount) {
			printf("No casualties.\n");
		}
	}
	for (i = 0; i < participants; i++) {
		if (contestants[i].alive) {
			printf("\n\n%s is victorious!\n", contestants[i].name);
		}
	}




	/*
	Hello Bit Heroes!
	Welcome to the 13th BHungerGames!
	I come to you as I can offer something you greatly want.... A place in my friendlist... You read right!
	I will give a friend slot to one of you..... IF you manage to outclass the other contenders...
	You will be placed in an arena.. an RNG arena. Each contestant has 95% of chance to survive in the arena....
	I will take **15 contestants**. Who dares come forward?
	Put a :shadown: if you want to participate. First 15 will enter the game.
	May the odds be ever in your favour.

	*/
}
