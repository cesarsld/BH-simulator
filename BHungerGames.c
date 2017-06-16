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

int scenarioDelay[83] = {0};

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
		char name[25];
		float chance;
		bool result;
		bool alive;
	} Contestants;

	Contestants contestants[200];

	strcpy(contestants[0].name, "LeonYuu");
	strcpy(contestants[1].name, "Bubs");
	strcpy(contestants[2].name, "Alterna");
	strcpy(contestants[3].name, "Harel1l");
	strcpy(contestants[4].name, "Kiwuy");
	strcpy(contestants[5].name, "Brewce");
	strcpy(contestants[6].name, "Zefi");
	strcpy(contestants[7].name, "Wifey");
	strcpy(contestants[8].name, "Jaquez2678");
	strcpy(contestants[9].name, "Elzylert");
	strcpy(contestants[10].name, "js0");
	strcpy(contestants[11].name, "ToxicBuilt");
	strcpy(contestants[12].name, "Moffles");
	strcpy(contestants[13].name, "Fultimetro");
	strcpy(contestants[14].name, "TheNamelessGod");
	strcpy(contestants[15].name, "claire06");
	strcpy(contestants[16].name, "KKyoji");
	strcpy(contestants[17].name, "Kyfo");
	strcpy(contestants[18].name, "Cestus");
	strcpy(contestants[19].name, "Zufeng");
	strcpy(contestants[20].name, "Smiiley");
	strcpy(contestants[21].name, "Somebody_cares");
	strcpy(contestants[22].name, "Mikeyje");
	strcpy(contestants[23].name, "Quos");
	strcpy(contestants[24].name, "Hambo");
	strcpy(contestants[25].name, "RedRidingHoodie");
	strcpy(contestants[26].name, "Sixcross31");
	strcpy(contestants[27].name, "Donovus");
	strcpy(contestants[28].name, "Ashlspiess");
	strcpy(contestants[29].name, "Bradbro");
	strcpy(contestants[30].name, "Skwakss");
	strcpy(contestants[31].name, "TheUltimatec");
	strcpy(contestants[32].name, "Fuzzyworth");
	strcpy(contestants[33].name, "DoktaR");
	strcpy(contestants[34].name, "Greatus");
	strcpy(contestants[35].name, "Rankaquion");
	strcpy(contestants[36].name, "MrXx");
	strcpy(contestants[37].name, "Yamatee");
	strcpy(contestants[38].name, "Minicrusader");
	strcpy(contestants[39].name, "Dookie");
	strcpy(contestants[40].name, "Mimimimu");
	strcpy(contestants[41].name, "HermesLou");
	strcpy(contestants[42].name, "BlankaSF2");
	strcpy(contestants[43].name, "Krowz");
	strcpy(contestants[44].name, "Mkalice");
	strcpy(contestants[45].name, "Grindalwald");
	strcpy(contestants[46].name, "Trakomo");
	strcpy(contestants[47].name, "afropinkunicorn");
	strcpy(contestants[48].name, "KVNCRLS");
	strcpy(contestants[49].name, "TopseyKrette");
	strcpy(contestants[50].name, "Mynameisjerf");
	strcpy(contestants[51].name, "Z0mbie");
	strcpy(contestants[52].name, "Yaptap");
	strcpy(contestants[53].name, "Pansä");
	strcpy(contestants[54].name, "Slugga");
	strcpy(contestants[55].name, "ArtysanHolo");
	strcpy(contestants[56].name, "WookeeCookee");
	strcpy(contestants[57].name, "DanielKF");
	strcpy(contestants[58].name, "GabMoji");
	strcpy(contestants[59].name, "Toones");
	strcpy(contestants[60].name, "Dridrixx");
	strcpy(contestants[61].name, "SteeTheHeezy");
	strcpy(contestants[62].name, "Marshy61");
	strcpy(contestants[63].name, "tardos");
	strcpy(contestants[64].name, "Chromosomes");
	strcpy(contestants[65].name, "ChesusCrust");
	strcpy(contestants[66].name, "Envy-");
	strcpy(contestants[67].name, "Coldbolla");
	strcpy(contestants[68].name, "LucidVindicity");
	strcpy(contestants[69].name, "Stranzi");
	strcpy(contestants[70].name, "Aphrooprimo");
	strcpy(contestants[71].name, "Mitcho");
	strcpy(contestants[72].name, "McCluckle");
	strcpy(contestants[73].name, "Paoz");
	strcpy(contestants[74].name, "Hatebox");
	strcpy(contestants[75].name, "kat");
	strcpy(contestants[76].name, "httpben");
	strcpy(contestants[77].name, "SelbyGoatWalker");
	strcpy(contestants[78].name, "BlackFable");
	strcpy(contestants[79].name, "UttanaHappy");
	strcpy(contestants[80].name, "tonytyzhang");
	strcpy(contestants[81].name, "NivM");
	strcpy(contestants[82].name, "CrushedPhantasm8");
	strcpy(contestants[83].name, "Tretavus");
	strcpy(contestants[84].name, "me_me");
	strcpy(contestants[85].name, "HomeDeport");
	strcpy(contestants[86].name, "KROMExRainbow");
	strcpy(contestants[87].name, "Pettirosso");
	strcpy(contestants[88].name, "JenseNN");
	strcpy(contestants[89].name, "Accused");
	strcpy(contestants[90].name, "BrioBlu");
	strcpy(contestants[91].name, "Nysenga");
	strcpy(contestants[92].name, "moonlightshadow");
	strcpy(contestants[93].name, "Uramikiro51");
	strcpy(contestants[94].name, "Zagrat");
	strcpy(contestants[95].name, "BillyIdol");
	strcpy(contestants[96].name, "Bytecycle");
	strcpy(contestants[97].name, "Kanwal22");
	strcpy(contestants[98].name, "Feliza");
	strcpy(contestants[99].name, "RawrSpaghetti");
	strcpy(contestants[100].name, "skillax");
	strcpy(contestants[101].name, "Lindys");
	strcpy(contestants[102].name, "Naho_o");
	strcpy(contestants[103].name, "MeatSuit");
	strcpy(contestants[104].name, "Gandoura");
	strcpy(contestants[105].name, "SuperKaley");
	strcpy(contestants[106].name, "acrokite");
	strcpy(contestants[107].name, "Murderlistic");
	strcpy(contestants[108].name, "gin7");
	strcpy(contestants[109].name, "Tychee");
	strcpy(contestants[110].name, "TroublingRain");
	strcpy(contestants[111].name, "Kentaroro");
	strcpy(contestants[112].name, "richiss");
	strcpy(contestants[113].name, "Enzazou");
	strcpy(contestants[114].name, "Forch");
	strcpy(contestants[115].name, "Dadam137");
	strcpy(contestants[116].name, "Mor_Tel");
	strcpy(contestants[117].name, "Vamboge");
	strcpy(contestants[118].name, "F0rc3");
	strcpy(contestants[119].name, "remmark999");
	strcpy(contestants[120].name, "Flowmp");
	strcpy(contestants[121].name, "Axiss");
	strcpy(contestants[122].name, "CandidHealer");
	strcpy(contestants[123].name, "ThermL");
	strcpy(contestants[124].name, "Aeux");
	strcpy(contestants[125].name, "Betroy");
	strcpy(contestants[126].name, "SvenB");
	strcpy(contestants[127].name, "giannizzero");
	strcpy(contestants[128].name, "Zayu");
	strcpy(contestants[129].name, "Hulir");
	strcpy(contestants[130].name, "Jaocy");
	strcpy(contestants[131].name, "Efrideet");
	strcpy(contestants[132].name, "Hisaya");
	strcpy(contestants[133].name, "Hiibye");
	strcpy(contestants[134].name, "Tyroke");
	strcpy(contestants[135].name, "niceAfroBro");
	strcpy(contestants[136].name, "Poltergiest");
	strcpy(contestants[137].name, "Thailoo");
	strcpy(contestants[138].name, "Wateryhoitytoity");
	strcpy(contestants[139].name, "Miskat");
	strcpy(contestants[140].name, "RexSsar");
	strcpy(contestants[141].name, "wuntsumfk");
	strcpy(contestants[142].name, "Horath");
	strcpy(contestants[143].name, "BlitzXKrieg");
	strcpy(contestants[144].name, "Herofox04");
	strcpy(contestants[145].name, "Bljat");
	strcpy(contestants[146].name, "Yamattaa");
	strcpy(contestants[147].name, "Frongipane");
	strcpy(contestants[148].name, "Ryansdryan");
	strcpy(contestants[149].name, "HyruleBoi");
	strcpy(contestants[150].name, "Tsumuyomi");
	strcpy(contestants[151].name, "Jaccob");
	strcpy(contestants[152].name, "Nicho");
	strcpy(contestants[153].name, "Grindar");
	strcpy(contestants[154].name, "STEFANOOO777");
	strcpy(contestants[155].name, "Catac");
	strcpy(contestants[156].name, "Silverlux");
	strcpy(contestants[157].name, "Dokutaku");
	strcpy(contestants[158].name, "Toucan");
	strcpy(contestants[159].name, "Hazkaz");
	strcpy(contestants[160].name, "xyrilyn");
	strcpy(contestants[161].name, "Thiccnugg");
	strcpy(contestants[162].name, "Nazuya");
	strcpy(contestants[163].name, "Ophilion");
	strcpy(contestants[164].name, "AngeryGod");
	strcpy(contestants[165].name, "KillerShadow");
	strcpy(contestants[166].name, "archss");
	strcpy(contestants[167].name, "Ankoty");
	strcpy(contestants[168].name, "Repra");
	strcpy(contestants[169].name, "Andark");
	strcpy(contestants[170].name, "DoubleIcaras");
	strcpy(contestants[171].name, "ChefSpicy");
	strcpy(contestants[172].name, "Skewe");
	strcpy(contestants[173].name, "Tentacule");
	strcpy(contestants[174].name, "lasagne29");
	strcpy(contestants[175].name, "vayne88");
	strcpy(contestants[176].name, "MrPaddy");
	strcpy(contestants[177].name, "HalfMassed");
	strcpy(contestants[178].name, "precise");
	strcpy(contestants[179].name, "KUSmurf");
	strcpy(contestants[180].name, "Mpobrien19");
	strcpy(contestants[181].name, "MGEKO");
	strcpy(contestants[182].name, "Transante");
	strcpy(contestants[183].name, "Kempha");
	strcpy(contestants[184].name, "Arodeth");
	strcpy(contestants[185].name, "Gegil");
	strcpy(contestants[186].name, "BowBe4God");
	strcpy(contestants[187].name, "Benmayk");
	strcpy(contestants[188].name, "LukeTheCut");
	strcpy(contestants[189].name, "GDI");
	strcpy(contestants[190].name, "co_giy");
	strcpy(contestants[191].name, "Esoum");
	strcpy(contestants[192].name, "inSIRmountable");
	strcpy(contestants[193].name, "Zader");
	strcpy(contestants[194].name, "Kristoff67");
	strcpy(contestants[195].name, "Hate99");
	strcpy(contestants[196].name, "Duuhhe");
	strcpy(contestants[197].name, "Franstyle");
	strcpy(contestants[198].name, "DarkConcept");
	strcpy(contestants[199].name, "Dintymley26");

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
