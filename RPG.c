#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define FILENAME "C:\\Users\\sundi\\Documents\\Oriont C\\RPG.SAVE\\save1.txt"
void Village();
void WorkVillageE();
void clearScreen();
void healE();
void elderwood1();
void fight1();
void fights();
void DungeonE();
void Goldenvale();
void Gvillage();
void menu();
void Eguild();
void Gguild();
void Gwork();

int Coins;
int playerLocation = 0;
int playerHealth = 100;
int playerStrength = 0;
char name[20] = " ";

void (*locationFunctions[])(void) = {Village, WorkVillageE, healE, elderwood1, DungeonE,
                                    Goldenvale, Gvillage, Gwork, Gguild, Eguild};

void updateLocation() {
    if (playerLocation >= 0 && playerLocation < sizeof(locationFunctions) / sizeof(locationFunctions[0])) {
        locationFunctions[playerLocation]();  // Call the function based on playerLocation
    } else {
        printf("Invalid location.\n");
    }
}

int load_variables(int *int1, int *int2, int *int3, int *int4, char *str) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0;  // Return 0 if file doesn't exist or can't be opened
    }

    // Read 3 integers and a string from the file
    fscanf(file, "%d %d %d %d %s", int1, int2, int3, int4, str);
    
    fclose(file);
    return 1;  // Return 1 if the variables were loaded successfully
}

void save_variables(int int1, int int2, int int3, int int4, const char *str) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write the 3 integers and the string to the file
    fprintf(file, "%d %d %d %d %s", int1, int2, int3, int4, str);
    
    fclose(file);
}

void Gquest(){
    clearScreen();
    printf("=======================Quest=======================\n");
    printf("|             GoldenVale Adventurer Guild         |\n");
    printf("| *Kill the Dragon Boss!                          |\n");
    printf("| *Reward = 100 Gold                              |\n");
    printf("|=================================================|\n");
    printf("| Tips : Dont forget to use heal, especially if   |\n");
    printf("|        your health is already under 40!         |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|           Have a safe trip traveler             |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("===================================================\n");
    getchar();
    getchar();


}

void clearScreen() {
    system("cls");
}

void Gwork(){
    playerLocation = 7;
    clearScreen();
    printf("=======================GoldenVale Job desk=======================\n");
    printf("??? : Welcome to GoldenVale job desk! which are you taking today?\n");
    printf("=======================      JOB LIST     =======================\n");
    printf("1. Farm\n");
    printf("2. Mine\n");
    printf("3. ");






}

void Gvillage(){
    playerLocation = 6;
    clearScreen();
    int pilihanG;
    printf("==============================GoldenVale Village===============================\n");
    printf("Nestled in the heart of a GoldenVale PLains, GoldenVale Village is known for its\n");
    printf("vibrant golden fields that shimmer under the sun, a result of the local grain’s\n");
    printf("unique hue. the street is full of people and markets\n");
    printf("=================================Player stats==================================\n");
    printf("Name : %s\n", name);
    printf("Health : %d\n", playerHealth);
    printf("Coins : %d\n", Coins);
    printf("Strength : %d\n", playerStrength);
    printf("====================================\n");
    printf("Where would you like to go?\n");
    printf("1. Work\n");
    printf("2. Visit Adventurer Guild\n");
    printf("3. aa\n");
    printf("Input Choice : ");
    scanf("%d", &pilihanG);
    switch(pilihanG){
        case 1:
            printf("a");
            break;
        case 2:
            Gguild();
            break;
        default:
            printf("INVALID INPUT!..press any to go back");
            getchar();
            getchar();
            Gvillage();
            break;            

    }
    




}

void fight3() {
    int enemyHealth = 200;
    int playerMana = 120;
    int enemyAttack;

    srand(time(NULL));
    printf("==============!!BOSS FIGHT!!==============\n");
    printf("A Dragon Boss appears!\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\nYour health: %d | Enemy health: %d | Your mana: %d\n", playerHealth, enemyHealth, playerMana);
        printf("Choose your attack:\n");
        printf("1. Quick Strike (10 damage, 10 mana)\n");
        printf("2. Power Blow (20 damage, 20 mana)\n");
        printf("3. Heavy Slash (30 damage, 30 mana)\n");
        printf("4. Special Attack (40 damage, 50 mana)\n");
        printf("5. Heal (Restores 50 health)\n");
        printf("Choose an option (1-5): ");

        int choice;
        scanf("%d", &choice);

        int playerAttack = 0;
        int manaCost = 0;

        switch (choice) {
            case 1:
                playerAttack = 10 + playerStrength;
                manaCost = 10;
                break;
            case 2:
                playerAttack = 20 + playerStrength;
                manaCost = 20;
                break;
            case 3:
                playerAttack = 30 + playerStrength;
                manaCost = 30;
                break;
            case 4:
                playerAttack = 40 + playerStrength;
                manaCost = 50;
                break;
            case 5:
                if (playerHealth < 100) {
                    playerHealth += 50;
                    if (playerHealth > 100) playerHealth = 100;
                    printf("You heal yourself for 50 health!\n");
                } else {
                    printf("Your health is already full!\n");
                }
                break;
            default:
                printf("Invalid choice! You lose your turn.\n");
                playerAttack = 0;
                manaCost = 0;
                break;
        }

        if (playerMana < manaCost) {
            printf("Not enough mana! You lose your turn.\n");
            playerAttack = 0;
        } else {
            enemyHealth -= playerAttack;
            if (enemyHealth < 0) enemyHealth = 0;

            playerMana -= manaCost;
            if (playerAttack > 0) {
                printf("You attack the enemy for %d damage!\n", playerAttack);
            }
        }

        if (enemyHealth == 0) {
            int pilihan;
            printf("==================VICTORY================\n");
            printf("You defeated the enemy!\n");
            printf("Youve been rewarwded with 350 gold coins!\n");
            Coins += 350;
            playerStrength += 2;
            printf("1. Continue fighting in dungeon\n");
            printf("2. Leave the Dungeon\n");
            printf("Enter your choice : ");
            scanf("%d", &pilihan);
            while (getchar() != '\n');

            switch (pilihan){
                case 1:
                    DungeonE();
                    break;
                case 2:
                    clearScreen();
                    elderwood1();
                    break;
                default:
                    printf("Invalid input! You have been sent out of the dungeon!\n");
                    getchar();
                    clearScreen();
                    elderwood1();
                    break;

            }



            break;
        }

        enemyAttack = rand() % 40 + 15;
        playerHealth -= enemyAttack;
        if (playerHealth < 0) playerHealth = 0;

        printf("The Dragon attacks you for %d damage!\n", enemyAttack);
        printf("===========================================\n");

        if (playerHealth == 0) {
            printf("==================Defeat===================\n");
            printf("You have been defeated by the enemy!\n");
            printf("100 coins has been taken from your balance\n");
            printf("for your healing fees!\n");
            Coins -= 100;
            playerHealth = 10;
            printf("you are sent back to the elderwood village\n");
            printf("Press enter to continue\n");
            getchar();
            getchar();
            clearScreen();
            Village();
            break;
        }

        playerMana += 10;
        if (playerMana > 120) playerMana = 120;
    }
}


void fight2() {
    int enemyHealth = 150;
    int playerMana = 100;
    int enemyAttack;

    srand(time(NULL));
    printf("==============!!ENEMY AMBUSH!!==============\n");
    printf("A wild Cursed knight appears!\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\nYour health: %d | Enemy health: %d | Your mana: %d\n", playerHealth, enemyHealth, playerMana);
        printf("Choose your attack:\n");
        printf("1. Quick Strike (10 damage, 10 mana)\n");
        printf("2. Power Blow (20 damage, 20 mana)\n");
        printf("3. Heavy Slash (30 damage, 30 mana)\n");
        printf("4. Special Attack (40 damage, 50 mana)\n");
        printf("5. Heal (Restores 50 health)\n");
        printf("Choose an option (1-5): ");

        int choice;
        scanf("%d", &choice);

        int playerAttack = 0;
        int manaCost = 0;

        switch (choice) {
            case 1:
                playerAttack = 10 + playerStrength;
                manaCost = 10;
                break;
            case 2:
                playerAttack = 20 + playerStrength;
                manaCost = 20;
                break;
            case 3:
                playerAttack = 30 + playerStrength;
                manaCost = 30;
                break;
            case 4:
                playerAttack = 40 + playerStrength;
                manaCost = 50;
                break;
            case 5:
                if (playerHealth < 100) {
                    playerHealth += 50;
                    if (playerHealth > 100) playerHealth = 100;
                    printf("You heal yourself for 50 health!\n");
                } else {
                    printf("Your health is already full!\n");
                }
                break;
            default:
                printf("Invalid choice! You lose your turn.\n");
                playerAttack = 0;
                manaCost = 0;
                break;
        }

        if (playerMana < manaCost) {
            printf("Not enough mana! You lose your turn.\n");
            playerAttack = 0;
        } else {
            enemyHealth -= playerAttack;
            if (enemyHealth < 0) enemyHealth = 0;

            playerMana -= manaCost;
            if (playerAttack > 0) {
                printf("You attack the enemy for %d damage!\n", playerAttack);
            }
        }

        if (enemyHealth == 0) {
            int pilihan;
            printf("==================VICTORY================\n");
            printf("You defeated the enemy!\n");
            printf("Youve been rewarwded with 200 gold coins!\n");
            Coins += 200;
            playerStrength += 1;
            printf("1. Continue fighting in dungeon\n");
            printf("2. Leave the Dungeon\n");
            printf("Enter your choice : ");
            scanf("%d", &pilihan);
            while (getchar() != '\n');

            switch (pilihan){
                case 1:
                    DungeonE();
                    break;
                case 2:
                    clearScreen();
                    elderwood1();
                    break;
                default:
                    printf("Invalid input! You have been sent out of the dungeon!\n");
                    getchar();
                    clearScreen();
                    elderwood1();
                    break;

            }



            break;
        }

        enemyAttack = rand() % 40 + 15;
        playerHealth -= enemyAttack;
        if (playerHealth < 0) playerHealth = 0;

        printf("The Cursed Knight attacks you for %d damage!\n", enemyAttack);
        printf("===========================================\n");

        if (playerHealth == 0) {
            printf("==================Defeat===================\n");
            printf("You have been defeated by the enemy!\n");
            printf("100 coins has been taken from your balance\n");
            printf("for your healing fees!\n");
            Coins -= 100;
            playerHealth = 10;
            printf("you are sent back to the elderwood village\n");
            printf("Press enter to continue\n");
            getchar();
            getchar();
            clearScreen();
            Village();
            break;
        }

        playerMana += 10;
        if (playerMana > 100) playerMana = 100;
    }
}

void fight1() {
    int enemyHealth = 60;
    int playerMana = 100;
    int enemyAttack;

    srand(time(NULL));
    printf("==============!!ENEMY AMBUSH!!==============\n");
    printf("A wild Slime appears!\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\nYour health: %d | Enemy health: %d | Your mana: %d\n", playerHealth, enemyHealth, playerMana);
        printf("Choose your attack:\n");
        printf("1. Quick Strike (10 damage, 10 mana)\n");
        printf("2. Power Blow (20 damage, 20 mana)\n");
        printf("3. Heavy Slash (30 damage, 30 mana)\n");
        printf("4. Special Attack (40 damage, 50 mana)\n");
        printf("5. Heal (Restores 50 health)\n");
        printf("Choose an option (1-5): ");

        int choice;
        scanf("%d", &choice);

        int playerAttack = 0;
        int manaCost = 0;

        switch (choice) {
            case 1:
                playerAttack = 10 + playerStrength;
                manaCost = 10;
                break;
            case 2:
                playerAttack = 20 + playerStrength;
                manaCost = 20;
                break;
            case 3:
                playerAttack = 30 + playerStrength;
                manaCost = 30;
                break;
            case 4:
                playerAttack = 40 + playerStrength;
                manaCost = 50;
                break;
            case 5:
                if (playerHealth < 100) {
                    playerHealth += 50;
                    if (playerHealth > 100) playerHealth = 100;
                    printf("You heal yourself for 50 health!\n");
                } else {
                    printf("Your health is already full!\n");
                }
                break;
            default:
                printf("Invalid choice! You lose your turn.\n");
                playerAttack = 0;
                manaCost = 0;
                break;
        }

        if (playerMana < manaCost) {
            printf("Not enough mana! You lose your turn.\n");
            playerAttack = 0;
        } else {
            enemyHealth -= playerAttack;
            if (enemyHealth < 0) enemyHealth = 0;

            playerMana -= manaCost;
            if (playerAttack > 0) {
                printf("You attack the enemy for %d damage!\n", playerAttack);
            }
        }

        if (enemyHealth == 0) {
            int pilihan;
            printf("==================VICTORY================\n");
            printf("You defeated the enemy!\n");
            printf("Youve been rewarwded with 100 gold coins!\n");
            Coins += 100;
            playerStrength += 1;
            printf("1. Continue fighting in dungeon\n");
            printf("2. Leave the Dungeon\n");
            printf("Enter your choice : ");
            scanf("%d", &pilihan);
            while (getchar() != '\n');

            switch (pilihan){
                case 1:
                    DungeonE();
                    break;
                case 2:
                    clearScreen();
                    elderwood1();
                    break;
                default:
                    printf("Invalid input! You have been sent out of the dungeon!\n");
                    getchar();
                    clearScreen();
                    elderwood1();
                    break;

            }



            break;
        }

        enemyAttack = rand() % 20 + 10;
        playerHealth -= enemyAttack;
        if (playerHealth < 0) playerHealth = 0;

        printf("The Slime attacks you for %d damage!\n", enemyAttack);
        printf("===========================================\n");

        if (playerHealth == 0) {
            printf("==================Defeat===================\n");
            printf("You have been defeated by the enemy!\n");
            printf("100 coins has been taken from your balance\n");
            printf("for your healing fees!\n");
            Coins -= 100;
            playerHealth = 10;
            printf("you are sent back to the elderwood village\n");
            printf("Press enter to continue\n");
            getchar();
            getchar();
            clearScreen();
            Village();
            break;
        }

        playerMana += 10;
        if (playerMana > 100) playerMana = 100;
    }
}

void fights() {
    int enemyHealth = 100;
    int playerMana = 100;
    int enemyAttack;

    srand(time(NULL));
    printf("==============!!ENEMY AMBUSH!!==============\n");
    printf("A wild Orc appears!\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\nYour health: %d | Enemy health: %d | Your mana: %d\n", playerHealth, enemyHealth, playerMana);
        printf("Choose your attack:\n");
        printf("1. Quick Strike (10 damage, 10 mana)\n");
        printf("2. Power Blow (20 damage, 20 mana)\n");
        printf("3. Heavy Slash (30 damage, 30 mana)\n");
        printf("4. Special Attack (40 damage, 50 mana)\n");
        printf("5. Heal (Restores 50 health)\n");
        printf("Choose an option (1-5): ");

        int choice;
        scanf("%d", &choice);

        int playerAttack = 0;
        int manaCost = 0;

        switch (choice) {
            case 1:
                playerAttack = 10 + playerStrength;
                manaCost = 10;
                break;
            case 2:
                playerAttack = 20 + playerStrength;
                manaCost = 20;
                break;
            case 3:
                playerAttack = 30 + playerStrength;
                manaCost = 30;
                break;
            case 4:
                playerAttack = 40 + playerStrength;
                manaCost = 50;
                break;
            case 5:
                if (playerHealth < 100) {
                    playerHealth += 50;
                    if (playerHealth > 100) playerHealth = 100;
                    printf("You heal yourself for 50 health!\n");
                } else {
                    printf("Your health is already full!\n");
                }
                break;
            default:
                printf("Invalid choice! You lose your turn.\n");
                playerAttack = 0;
                manaCost = 0;
                break;
        }

        if (playerMana < manaCost) {
            printf("Not enough mana! You lose your turn.\n");
            playerAttack = 0;
        } else {
            enemyHealth -= playerAttack;
            if (enemyHealth < 0) enemyHealth = 0;

            playerMana -= manaCost;
            if (playerAttack > 0) {
                printf("You attack the enemy for %d damage!\n", playerAttack);
            }
        }

        if (enemyHealth == 0) {
            int pilihan;
            printf("==================VICTORY================\n");
            printf("You defeated the enemy!\n");
            printf("Youve been rewarwded with 150 gold coins!\n");
            Coins += 150;
            playerStrength += 1;
            printf("1. Continue fighting in dungeon\n");
            printf("2. Leave the Dungeon\n");
            printf("Enter your choice : ");
            scanf("%d", &pilihan);
            while (getchar() != '\n');

            switch (pilihan){
                case 1:
                    DungeonE();
                    break;
                case 2:
                    clearScreen();
                    elderwood1();
                    break;
                default:
                    printf("Invalid input! You have been sent out of the dungeon!\n");
                    getchar();
                    clearScreen();
                    elderwood1();
                    break;

            }



            break;
        }

        enemyAttack = rand() % 30 + 15;
        playerHealth -= enemyAttack;
        if (playerHealth < 0) playerHealth = 0;

        printf("The Orc attacks you for %d damage!\n", enemyAttack);
        printf("===========================================\n");

        if (playerHealth == 0) {
            printf("==================Defeat===================\n");
            printf("You have been defeated by the enemy!\n");
            printf("100 coins has been taken from your balance\n");
            printf("for your healing fees!\n");
            Coins -= 100;
            playerHealth = 10;
            printf("you are sent back to the elderwood village\n");
            printf("Press enter to continue\n");
            getchar();
            getchar();
            clearScreen();
            Village();
            break;
        }

        playerMana += 10;
        if (playerMana > 100) playerMana = 100;
    }
}

void Goldenvale(){
    playerLocation = 5;
    int pilihans;
    clearScreen();
    printf("==============Goldenvale Plains==============\n");
    printf("This place is quite safe, there isnt much monster\n");
    printf("around but the slimes, there are some houses nearby\n");
    printf("=============Player stats============\n");
    printf("Name : %s\n", name);
    printf("Health : %d\n", playerHealth);
    printf("Coins : %d\n", Coins);
    printf("Strength : %d\n", playerStrength);
    printf("====================================\n");
    printf("Where would you like to go?\n");
    printf("1. Visit Goldenvale Village\n");
    printf("2. Continue walking\n");
    printf("3. Go back\n");
    printf("Insert choice : ");
    scanf("%d", &pilihans);
    while (getchar() != '\n');

    switch (pilihans){
        case 1:
            Gvillage();
            break;
        case 2:
            printf("a");
            break;
        case 3:
            elderwood1();
            break;


    }


}

void healE(){
    playerLocation = 2;
    clearScreen();
    int choicem;
    printf("===========Elderwood Infirmary=========\n");
    printf("Medic : Welcome traveler, How can i assist you today?\n");
    printf("pick your respond\n");
    printf("1. \"I need a heal\" (50 Gold coins)\n");
    printf("2. \"Bye!\"\n");
    printf("Insert your respond : ");
    scanf("%d", &choicem);
    while (getchar() != '\n');

    switch(choicem){
        case 1:
            if (Coins >= 50 && playerHealth < 100){
                playerHealth = 100;
                Coins -= 50;
                printf("Medic : Ive healed you! have a safe trip traveler\n");
                printf("You now have %d Coins left\n", Coins);
            } else if (playerHealth == 100){
                printf("Medic : Your health is already full! you dont need healing\n");
            } else if (Coins < 50 && Coins >= 0){
                printf("Medic : Im afraid you dont have enough coins..\n");
            } else if (Coins < 0){
                printf("Medic : oh my.. it seems like youre in a debt..\n");
                printf("Medic : Sorry but i cant help you\n");
            }
            printf("Press enter to continue\n");
            getchar();
            clearScreen();
            Village();
            break;
        case 2:
            printf("Medic : farewell! have a safe trip traveler!\n");
            getchar();
            clearScreen();
            Village();
            break;
        default:
            printf("Invalid input! press enter to go back\n");
            getchar();
            clearScreen();
            Village();
            break;
    }

}

void DungeonE(){
    playerLocation = 4;
    clearScreen();
    int enemychoice;
    printf("==============DUNGEON==============\n");
    printf("Youre walking inside the dungeon of elderwood..\n");
    printf("its dark and cold here.\n");
    printf("Press enter to continue..\n");
    getchar();
    srand(time(NULL));
    enemychoice = rand() % 4 + 1;

    switch(enemychoice){
        case 1:
            clearScreen();
            fights();
            break;
        case 2:
            clearScreen();
            fight1();
            break;
        case 3:
            clearScreen();
            fight2();
            break;
        case 4:
            clearScreen();
            fight3();
            break;
    }
}

void WorkVillageE(){
    playerLocation = 1;
    clearScreen();
    int choices;
    printf("===========Elderwood Job desk=========\n");
    printf("??? : Welcome traveler! Which job would you take today?\n");
    printf("Choose below\n");
    printf("1. Mining \n");
    printf("2. Fishing \n");
    printf("3. Nevermind\n");
    printf("Insert your choice : ");
    scanf("%d", &choices);
    while (getchar() != '\n');

    srand(time(NULL));
    int salary;

    switch(choices){
        case 1:
            salary = rand() % 30 + 10;
            Coins += salary;
            printf("You worked in a gold mine and gained %d gold coins\n", salary);
            printf("Press enter to go back..\n");
            getchar();
            clearScreen();
            Village();
            break;
        case 2:
            salary = rand() % 20 + 10;
            Coins += salary;
            printf("You sold the fish you catched and gained %d gold coins\n", salary);
            printf("Press enter to go back..\n");
            getchar();
            clearScreen();
            Village();
            break;
        case 3:
            clearScreen();
            Village();
            break;
        default:
            printf("invalid choice! Press enter to go back!\n");
            getchar();
            clearScreen();
            Village();
            break;
    }

}

void elderwood1(){
    playerLocation = 3;
    int choicef;
    clearScreen();
    printf("===========Elderwood Forest=========\n");
    printf("You are now outside the Elderwood village\n");
    printf("its quite a big forest outside.\n");
    printf("You found a dungeon nearby.\n");
    printf("=============Player stats============\n");
    printf("Name : %s\n", name);
    printf("Health : %d\n", playerHealth);
    printf("Coins : %d\n", Coins);
    printf("Strength : %d\n", playerStrength);
    printf("====================================\n");
    printf("Where would you like to go?\n");
    printf("1. Elderwood Dungeon\n");
    printf("2. Continue walking\n");
    printf("3. Go back to the village\n");
    printf("Insert choice : ");
    scanf("%d", &choicef);
    while (getchar() != '\n');

    switch(choicef){
        case 1:
            DungeonE();
            break;
        case 2:
            Goldenvale();
            break;
        case 3:
            Village();
            break;
        default:
            printf("Invalid choice, press enter to go back!\n");
            getchar();
            clearScreen();
            elderwood1();
            break;
    }



}

void Gguild(){
    playerLocation = 8;
    int pilihs;
    clearScreen();
    printf("==================GOLDENVALE ADVENTURER GUILD==================\n");
    printf("The Adventurer's Guild stands proudly at the heart of town\n");
    printf("Inside, the air hums with the bustle of adventurers coming and going\n");
    printf("a large board displays quests for those brave enough to take them on.\n");
    printf("===============================================================\n");
    printf("Name : %s\n", name);
    printf("Health : %d\n", playerHealth);
    printf("Coins : %d\n", Coins);
    printf("Strength : %d\n", playerStrength);
    printf("What do you do next?\n");
    printf("1. Save Progress\n");
    printf("2. Check Quest Board\n");
    printf("3. Go back\n");
    printf("Enter choice : ");
    scanf("%d", &pilihs);
    switch(pilihs){
        case 1:
            save_variables(Coins, playerHealth, playerStrength, playerLocation, name);
            printf("DATA HAS BEEN SUCCSESSFULLY SAVED :D!\n");
            printf("Press enter to continue..");
            getchar();
            getchar();
            Gvillage();
            break;
        case 2:
            Gquest();
            break;
        case 3:
            Gvillage();
            break;
        default:
            printf("Invalid choice, press enter to go back!\n");
            getchar();
            clearScreen();
            Gguild();
            break;
            
    }
}

void Eguild(){
    playerLocation = 9;
    int pilihs;
    clearScreen();
    printf("==================ELDERWOOD ADVENTURER GUILD==================\n");
    printf("The Adventurer's Guild stands proudly at the heart of town\n");
    printf("Inside, the air hums with the bustle of adventurers coming and going\n");
    printf("a large board displays quests for those brave enough to take them on.\n");
    printf("==============================================================\n");
    printf("Name : %s\n", name);
    printf("Health : %d\n", playerHealth);
    printf("Coins : %d\n", Coins);
    printf("Strength : %d\n", playerStrength);
    printf("What do you do next?\n");
    printf("1. Save Progress\n");
    printf("2. Check Quest Board\n");
    printf("3. Go back\n");
    printf("Enter choice : ");
    scanf("%d", &pilihs);
    switch(pilihs){
        case 1:
            save_variables(Coins, playerHealth, playerStrength, playerLocation, name);
            printf("DATA HAS BEEN SUCCSESSFULLY SAVED :D!\n");
            printf("Press enter to continue..");
            getchar();
            getchar();
            Village();
            break;
        case 2:
            Village();
            break;
        case 3:
            Village();
            break;
        default:
            printf("Invalid choice, press enter to go back!\n");
            getchar();
            clearScreen();
            Eguild();
            break;
            
    }
}

void Village(){
    playerLocation = 0;
    int choice;
    clearScreen();
    printf("===========Elderwood Village=========\n");
    printf("You are now residing in Elderwood Village\n");
    printf("=============Player stats============\n");
    printf("Name : %s\n", name);
    printf("Health : %d\n", playerHealth);
    printf("Coins : %d\n", Coins);
    printf("Strength : %d\n", playerStrength);
    printf("What do you do next?\n");
    printf("1. Work \n");
    printf("2. Visit Adventurer guild \n");
    printf("3. Seek a healer \n");
    printf("4. Leave the village\n");
    printf("Insert your choice : ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    switch(choice){
        case 1:
            WorkVillageE();
            break;
        case 2:
            Eguild();
            break;
        case 3:
            healE();
            break;
        case 4:
            elderwood1();
            break;
        default:
            printf("Invalid choice, press enter to go back!\n");
            getchar();
            clearScreen();
            Village();
            break;
    }
}

void menu() {
    printf("==========Text Adventure Game=========\n");
    printf("Welcome to the Text Adventure Game!\n");
    printf("Make a name for your character! ");
    scanf("%49s", name);
    getchar();
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');
    Village();
}

int main(){
    int pilih;
    printf("==========Text Adventure Game=========\n");
    printf("Welcome to the Text Adventure Game!\n");
    printf("Would you like to start over or load a save?\n");
    printf("1.\t Load Slot 1\n");
    printf("2.\t New game 1\n");
    printf("Insert choice : ");
    scanf("%d", &pilih);
    switch(pilih){
        case 1:
            if (load_variables(&Coins, &playerHealth, &playerStrength, &playerLocation, name)) {
                printf("Game data loaded successfully!\n");
                printf("Coins: %d\n", Coins);
                printf("Health: %d\n", playerHealth);
                printf("Strength: %d\n", playerStrength);
                printf("Player name: %s\n", name);
                printf("Press enter to continue..");
                getchar();
                getchar();
                updateLocation();

            } else {
                printf("No saved data found. Starting a new game.\n");
                printf("Press enter to continue..");
                getchar();
                getchar();
                menu();
            }
            break;
        case 2:
            clearScreen();
            menu();
            break;


    }

    return 0;
}