//
//  BHSimulator.c
//  BH Simulator
//
//  Created by Cesar Salad Jaimes on 20/04/2017.
//  Copyright © 2017 Cesar Salad Jaimes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "BHSimulator.h"

void Scenarios(char name[20], char nameA[20], char nameB[20], int player) {

	bool scenarioSelected = false;
	while (!scenarioSelected) {
		int a = rand() % 61;
		if (a == 0 && player > 2) {
			scenarioSelected = true;
			printf("%s made an alliance with %s to kill %s. But %s shouldn't have trusted %s... %s has killed %s.\n\n", name, nameA, nameB, name, nameA, nameA, name);
		}
		else if (a == 1) {
			scenarioSelected = true;
			printf("%s stepped on a mine. What a shame.\n\n", name);
		}
		else if (a == 2) {
			scenarioSelected = true;
			printf("%s is extremely hungry. He hasn't eaten for days. He sees %s eating some berries in the forest but %s drops dead. ''I wonder what human flesh tastes like!'' tells %s to himself.\n\n", nameA, name, name, nameA);
		}
		else if (a == 3) {
			scenarioSelected = true;
			printf("%s got mauled by genetically modified Korgz.\n\n", name);
		}
		else if (a == 4) {
			scenarioSelected = true;
			printf("%s died of a wound infection inflicted by %s whilst fighting for some ressources.\n\n", name, nameA);
		}
		else if (a == 5) {
			scenarioSelected = true;
			printf("A giant rock fell on %s's head... But how?\n\n", name);
		}
		else if (a == 6) {
			scenarioSelected = true;
			printf("It's a miracle! %s escaped from the deadly Nosdoodoo! Oh wait! Never mind, %s just got eaten by Blubber...\n\n", name, name);
		}
		else if (a == 7) {
			scenarioSelected = true;
			printf("Taters has muted %s once and for all.\n\n", name);
		}
		else if (a == 8) {
			scenarioSelected = true;
			printf("Oh no! %s has just bet his life with Grimz! And he lost :( .\n\n", name);
		}
		else if (a == 9) {
			scenarioSelected = true;
			printf("%s died of sodium chloride overdose.\n\n", name);
		}
		else if (a == 10) {
			scenarioSelected = true;
			printf("%s has just seen RNGesus in front of him! He asks him if he can win and to that question, RNGesus responds:'nope'. %s dies.\n\n", name, name);
		}
		else if (a == 11) {
			scenarioSelected = true;
			printf("What people don't know is that Mimziy is very territorial... Oh look! %s has stepped into his territory! Bye bye %s.\n\n", name, name);
		}
		else if (a == 12) {
			scenarioSelected = true;
			printf("%s broke his ankle. Is that a Zorg I see rushing towards %s? Yes, yes it is.\n\n", name, name);
		}
		else if (a == 13) {
			scenarioSelected = true;
			printf("%s finds some food on the ground! Great news.... for %s that was waiting for him.  %s kills %s. \n\n", name, nameA, nameA, name);
		}
		else if (a == 14) {
			scenarioSelected = true;
			printf("%s is steadily aiming his arrow to %s, drinking water from the river. *woosh* Bullseye\n\n", nameA, name);
		}
		else if (a == 15) {
			scenarioSelected = true;
			printf("A wild Kov' Arg appears!'Death or snusnu ? '.'Death' replies %s.'Farewell... Death....By snusnu!'\n\n", name);
		}
		else if (a == 16) {
			scenarioSelected = true;
			printf("%s encounters Warty.Warty tells him to kiss him so he could transform into a beautiful princess. %s is way too naive! As soon as %s kisses Warty, his poison consumes him into a pile of goo...\n\n", name, name, name);
		}
		else if (a == 17) {
			scenarioSelected = true;
			printf("%s just died\n.\n.\n.\n.\n jk!\n %s died in his place.Ha.", nameA, name);
		}
		else if (a == 18) {
			scenarioSelected = true;
			printf("%s spent all his gems on large eggs and got nothing... %s committed suicide\n\n", name, name);
		}
		else if (a == 19) {
			scenarioSelected = true;
			printf("%s sees a big footprint on the ground.It looks like a yeti's footprint ? Yup.Yeti just ate %s.\n\n", name, name);
		}
		else if (a == 20) {
			scenarioSelected = true;
			printf("%s found the one ring to rule them all!He will posses incredible power!Watch out!A Golum is charging at you!Too late : (\n\n", name);
		}
		else if (a == 21) {
			scenarioSelected = true;
			printf("%s is allergic to peanuts.He was unaware of it and just ate some that %s gave him... Coincidence ? I think not!\n\n", name, nameA);
		}
		else if (a == 22) {
			scenarioSelected = true;
			printf("%s disconnected in the middle of Kaleido heroic fight... : rip:\n\n", name);
		}
		else if (a == 23) {
			scenarioSelected = true;
			printf("%s decided to go hunt for food. %s shoots his arrow - but whats this? the arrow ricochets and unfortunately hits %s in the knee... Damn RNG!", name, name, name);
		}
		else if (a == 23) {
			scenarioSelected = true;
			printf(" %s dies as a result of shaving. %s was unaware that %s had dipped his shaving knife in a poisonous mixture... \n\n", name, name, nameA);
		}
		else if (a == 24) {
			scenarioSelected = true;
			printf(" The powerful wizard %s is on the run and accidentally trips over his own beard, falling to his death.. \n\n", name);
		}
		else if (a == 25) {
			scenarioSelected = true;
			printf("Gobby loves stealing from people.He just stole all of %s's money... %s died of depression.\n\n", name, name);
		}
		else if (a == 26) {
			scenarioSelected = true;
			printf("%s just broke Olxaroth's card castle! Filled with anger, Olxaroth's reduces %s in a pile of ashes. /n/n", name, name);
		}
		else if (a == 27) {
			scenarioSelected = true;
			printf(" %s is smart, and decides to hide up in the trees. \n Could this be it? is it? YES! - its time to drop the blubber suit and turn into a buuutiful butterfly! Unfortunately, fairytales are not real, and %s didnt fly, but fell to his death \n\n", name, name);
		}
		else if (a == 28) {
			scenarioSelected = true;
			printf(" %s thought it would be wise to bring a stick to a sword fight... %s dies.. \n\n", name, name);
		}
		else if (a == 29) {
			scenarioSelected = true;
			printf("Everyone hate Mimeido. %s agrees to this statement.But %s forgot Mimeido could oneshot him : ) \n\n", name, name);
		}
		else if (a == 30) {
			scenarioSelected = true;
			printf(" %s is sneaking around the castle, when suddenly he runs into Gemmroid! 'Do you even lift bro?' - says Gemmroid. Filled with shame and un-impressive gains %s must forfeit.. \n\n", name, name);
		}
		else if (a == 31) {
			scenarioSelected = true;
			printf("%s is walking along side a cliff and slips!He catches the edge. %s sees all the action, approaches %s and flips a coin.'heads, you live'.It's tails : / \n\n", name, nameA, name);
		}
		else if (a == 32) {
			scenarioSelected = true;
			printf("The gamemakers send in a swarm of Melvinsteins to disrupt the game! While attempting to run from them, %s tripped and fell, allowing the Melvinsteins to eat him alive. \n\n", name);
		}
		else if (a == 33) {
			scenarioSelected = true;
			printf("%s makes a run for the remaining items in the Cornucopia! Little did %s know that %s was waiting with an enormous Glimmer, ready to decapitate. %s 's head  \n\n", name, name, nameA, name);
		}
		else if (a == 34) {
			scenarioSelected = true;
			printf("Knowing %s cannot survive alone, %s sends out a friend request: 'lvl 6 looking for lvl 250+ to help me complete r2 heroic!' %s 's request is denied, and promptly dies without an alliance. \n\n", name, name, name);
		}
		else if (a == 35) {
			scenarioSelected = true;
			printf("As %s runs through a dungeon, %s spies a Mimeido! But he didn't watch all his items and Mimeido ate his foot pretending to be a sock. \n\n", name, name);
		}
		else if (a == 36) {
			scenarioSelected = true;
			printf("%s was foraging for food when they spotted a wild Shrump! Unfortunately, %s voted for Nyxn in the last Bit Heroes election, and when Shrump heard about that, he banished %s for life. \n\n", name, name, name);
		}
		else if (a == 37) {
			scenarioSelected = true;
			printf("%s was doing just fine up until they proposed that Bit Heroes should have more fan fiction. Tarri disagreed, and laid down the banhammer. \n\n", name);
		}
		else if (a == 38) {
			scenarioSelected = true;
			printf("Krusty always wanted to open the Krusty Krab....And he's pretty sad about it... For that reason, he crits %s for no reason.\n\n", name);
		}
		else if (a == 39) {
			scenarioSelected = true;
			printf(" %s runs into a wild gang of Pengeys. Shaking with fear and regret of the paths taken, %s decides to make a run for it... \n %s underestimated the powers of this wild gang, and quickly realises, he dun goof'd \n\n", name, name, name);
		}
		else if (a == 40) {
			scenarioSelected = true;
			printf("%s didn't believe Wemmbo crit chance was high enough to worry about... Boy was he wrong\n\n", name);
		}
		else if (a == 41) {
			scenarioSelected = true;
			printf("%s didn't use CAPS in Salt_mines.Byleth bans him forever!\n\n", name);
		}
		else if (a == 42) {
			scenarioSelected = true;
			printf("%s and %s teamed up in an alliance, but in a cruel twist of fate, %s broke that alliance and pushed %s off a cliff. \n\n", name, nameA, nameA, name);
		}
		else if (a == 43) {
			scenarioSelected = true;
			printf("After hours of searching, %s has found a pool from which to drink! . . . but it turns out to be a pool of Kaleido's tears. %s is banished to R2 never to return. \n\n", name, name);
		}
		else if (a == 44) {
			scenarioSelected = true;
			printf("%s and %s have found a Gemmroid! He challenges both of them to leg day. Sadly, %s gets rhabdomyalysis and dies. \n\n", name, nameA, name);
		}
		else if (a == 45) {
			scenarioSelected = true;
			printf("%s finds a rare candy on the ground! But it turns out to be ground candy. %s vomits the entire contents of his stomach and dies of malnutrition. \n\n", name, name);
		}
		else if (a == 46) {
			scenarioSelected = true;
			printf("%s ventures into world chat! Oh no! He is too high of a level and is spammed to death. \n\n", name);
		}
		else if (a == 47) {
			scenarioSelected = true;
			printf("'Want to hear a joke?' Warty said to %s. %s said no, so Warty ate him. \n\n", name, name);
		}
		else if (a == 48) {
			scenarioSelected = true;
			printf("Walking up the mountain of Lost Heroes, %s encountered Vedic! Vedic draws and quarters %s with his samurai sword. \n\n", name, name);
		}
		else if (a == 49) {
			scenarioSelected = true;
			printf(" Without skipping a beat, %s hides, as he can hear footsteps closing in... \n %s sneaks up on %s... %s dies. \n\n", name, nameA, name, name);
		}
		else if (a == 50) {
			scenarioSelected = true;
			printf(" While on the hunt for some delicious booty, %s unfortunately becomes the prey to the ferocious Dina.. \n\n", name);
		}
		else if (a == 51) {
			scenarioSelected = true;
			printf("%s attempts to beat Blasian in an Astaroth Flag pvp tournament! %s runs out of time, money, points, and sanity. \n\n", name, name);
		}
		else if (a == 52) {
			scenarioSelected = true;
			printf("%s sees a [K] member. OMG! Unfortunately, the [K] member doesn't have times and kills %s.\n\n", name, name);
		}
		else if (a == 53) {
			scenarioSelected = true;
			printf("%s pulls a Leeroy Jenkins and rushes into z4d4. We all know how that turns out. \n\n", name);
		}
		else if (a == 54) {
			scenarioSelected = true;
			printf(" Covered in dirt, and tired from battle %s decides that its time to take a swim in the nearby lake. %s forgot he couldnt swim.. rip \n\n", name, name);
		}
		else if (a == 55) {
			scenarioSelected = true;
			printf("%s dies.Like, nothing happened to him, he just collapsed like a pile of shit. : / \n\n", name);
		}
		else if (a == 56) {
			scenarioSelected = true;
			printf("%s makes the mistake of eating Yeti's Frozen Spaghetti and is frozen from the inside out. \n\n", name);
		}
		else if (a == 57) {
			scenarioSelected = true;
			printf("%s sees a mysterious shadow near the horizon.Who could it be ? Nanananananananana, Bubbo! And he's here to wreck %s's booty!\n\n", name, name);
		}
		else if (a == 58) {
			scenarioSelected = true;
			printf("%s attempts to talk to Quinn one times too many. Didn't you get the hint the 54th time you asked? \n\n", name);
		}
		else if (a == 59) {
			scenarioSelected = true;
			printf("%s quipped mirror wings and astaroth armor, got mistaken by Warty as a fly. %s died due to digestive chemicals...\n\n", name, name);
		}
		else if (a == 60) {
			scenarioSelected = true;
			printf("%s and %s have been walking all day. Very tired, they both decide to have a quick picnic. Unfortunately a swarm of Terrumps covered the sky dark and went in for the kill.. \n %s managed to get away, but %s wasnt so lucky.. \n\n", name, nameA, nameA, name);
		}
	}


}

void BHungerGames() {
	//
	int participants = 100;
	int t;
	typedef struct BHG {
		char name[20];
		float chance;
		bool result;
		bool alive;
	} Contestants;

	Contestants contestants[100];

	strcpy(contestants[0].name, "Duydesbois");
	strcpy(contestants[1].name, "Beaudet");
	strcpy(contestants[2].name, "Jasminee");
	strcpy(contestants[3].name, "Noktuk");
	strcpy(contestants[4].name, "Hai");
	strcpy(contestants[5].name, "Penghuynh");
	strcpy(contestants[6].name, "remmark999");
	strcpy(contestants[7].name, "Taphos");
	strcpy(contestants[8].name, "riplakiish");
	strcpy(contestants[9].name, "Yozu");
	strcpy(contestants[10].name, "MeatSuit");
	strcpy(contestants[11].name, "Kiwuy");
	strcpy(contestants[12].name, "Broximunda");
	strcpy(contestants[13].name, "Venixor");
	strcpy(contestants[14].name, "Mikalangelo");
	strcpy(contestants[15].name, "ThermL");
	strcpy(contestants[16].name, "xionicmadness");
	strcpy(contestants[17].name, "Krealor");
	strcpy(contestants[18].name, "Aimac");
	strcpy(contestants[19].name, "Bubs");
	strcpy(contestants[20].name, "kyfo");
	strcpy(contestants[21].name, "Flilia");
	strcpy(contestants[22].name, "ThunderBird");
	strcpy(contestants[23].name, "Alejox");
	strcpy(contestants[24].name, "Sinnar");
	strcpy(contestants[25].name, "Pyna");
	strcpy(contestants[26].name, "Lagenta");
	strcpy(contestants[27].name, "Vireo");
	strcpy(contestants[28].name, "kanonbaal");
	strcpy(contestants[29].name, "Recab");
	strcpy(contestants[30].name, "ACPhoenix");
	strcpy(contestants[31].name, "LG1T");
	strcpy(contestants[32].name, "ZeroCrash");
	strcpy(contestants[33].name, "Rittoru");
	strcpy(contestants[34].name, "RendingHavoc");
	strcpy(contestants[35].name, "Skip58");
	strcpy(contestants[36].name, "co_giy");
	strcpy(contestants[37].name, "Halvsover");
	strcpy(contestants[38].name, "Herkk");
	strcpy(contestants[39].name, "Moqcev");
	strcpy(contestants[40].name, "Mor_Tel");
	strcpy(contestants[41].name, "MrSavageaf");
	strcpy(contestants[42].name, "MissMariss26");
	strcpy(contestants[43].name, "derrkkk");
	strcpy(contestants[44].name, "LittlePie ");
	strcpy(contestants[45].name, "onefour");
	strcpy(contestants[46].name, "Fipps");
	strcpy(contestants[47].name, "Freld");
	strcpy(contestants[48].name, "Futuro");
	strcpy(contestants[49].name, "stolve");
	strcpy(contestants[50].name, "Skewe");
	strcpy(contestants[51].name, "jooe15");
	strcpy(contestants[52].name, "chiefebola");
	strcpy(contestants[53].name, "Skamic");
	strcpy(contestants[54].name, "js0");
	strcpy(contestants[55].name, "Kempha");
	strcpy(contestants[56].name, "FistyKramer");
	strcpy(contestants[57].name, "N3RFED");
	strcpy(contestants[58].name, "BrioBlu");
	strcpy(contestants[59].name, "JakobT");
	strcpy(contestants[60].name, "Efikaz");
	strcpy(contestants[61].name, "ShumanShu");
	strcpy(contestants[62].name, "Atomic1289");
	strcpy(contestants[63].name, "Elysabelle");
	strcpy(contestants[64].name, "CspaceJ");
	strcpy(contestants[65].name, "Sandyoso");
	strcpy(contestants[66].name, "Snuffles213");
	strcpy(contestants[67].name, "HalfMassed");
	strcpy(contestants[68].name, "Qwipgar");
	strcpy(contestants[69].name, "TheUltimatec");
	strcpy(contestants[70].name, "MilaKunis");
	strcpy(contestants[71].name, "Cafall");
	strcpy(contestants[72].name, "MUSKELKATER");
	strcpy(contestants[73].name, "Aphrooprimo");
	strcpy(contestants[74].name, "KKyoji");
	strcpy(contestants[75].name, "Nick-Fury");
	strcpy(contestants[76].name, "DKHue");
	strcpy(contestants[77].name, "Gegil");
	strcpy(contestants[78].name, "Bhekk");
	strcpy(contestants[79].name, "Shinjifo");
	strcpy(contestants[80].name, "gavin1257");
	strcpy(contestants[81].name, "Pyrø");
	strcpy(contestants[82].name, "Sypress");
	strcpy(contestants[83].name, "Grindalwald");
	strcpy(contestants[84].name, "asuhdudedab");
	strcpy(contestants[85].name, "LOXMATblY");
	strcpy(contestants[86].name, "Arcwind");
	strcpy(contestants[87].name, "Cheesewizard");
	strcpy(contestants[88].name, "mellidus");
	strcpy(contestants[89].name, "kitchenkit");
	strcpy(contestants[90].name, "CrushedPhantasm8");
	strcpy(contestants[91].name, "Zarla");
	strcpy(contestants[92].name, "Cestus");
	strcpy(contestants[93].name, " iamJosh");
	strcpy(contestants[94].name, "tonytyzhang");
	strcpy(contestants[95].name, "Zayu");
	strcpy(contestants[96].name, "PyroCat");
	strcpy(contestants[97].name, "ishotboston");
	strcpy(contestants[98].name, " Null");
	strcpy(contestants[99].name, "archss");


	for (t = 0; t < participants; t++) {
		contestants[t].chance = 95;
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
	int playerAlive = 0;
	for (j = 0; j < participants; j++) {
		if (contestants[j].alive) {
			playerAlive++;
		}
	}
	int i;
	int a = 0, b = 0;
	while (playerAlive > 1) {
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
	Welcome to the 8th BHungerGames!
	I come to you as I can offer something you greatly want.... A place in my friendlist... You read right!
	I will give a friend slot to one of you..... IF you manage to outclass the other contenders...
	You will be placed in an arena.. an RNG arena. Each contestant has 95% of chance to survive in the arena....
	I will take **15 contestants**. Who dares come forward?
	Put a :shadown: if you want to participate. First 15 will enter the game.
	May the odds be ever in your favour.

	*/
}
