#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

bool isLaunched;
bool isLocked;
bool isGod;
bool isBug;
int bugPin;
int secureAccessCode;
int loopCounter;
enum input{BUG, YES, NO};

void loading() {
    for (int i = 0; i < 3; i++) {
        cout << ". " << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

string getUser() {
    string userIn;
    do {
        cin >> userIn;
        for (int i = 0; i < userIn.size(); i++) {
            if (islower(userIn[i])) {
                userIn[i] = toupper(userIn[i]);
            }
        }
    } while (userIn != "YES" && userIn != "NO" && userIn != "BUG" && userIn != "UNLOCK");

    return userIn;
}

input enumUserChoice(string userIn) {
    if (userIn == "YES") {
        return YES;
    } else if (userIn == "NO") {
        return NO;
    } else {
        return BUG;
    }
}

int getCode() {
    int userCode;
    do {
        cin >> userCode;
    } while (userCode == isalpha(userCode));
    return userCode;
}

void override() {
    system("clear");
    for (int i = 0; i < 6; i++) {
        cout << "Attempting Override" << endl;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << ". " << flush;
                this_thread::sleep_for(chrono::milliseconds(500));
            }
        }
        system("clear");
    }
    system("clear");
    this_thread::sleep_for(chrono::milliseconds(10000));

    if (isLocked) {
        for (int i = 0; i < 5; i++) {
            cout << "This screen has been locked" << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            system("clear");
            this_thread::sleep_for(chrono::milliseconds(250));
        }
    } else {
        for (int i = 0; i < 5; i++) {
            cout << R"(
            █████╗  ██████╗  ██████╗██╗  ██╗███████╗███████╗    ██████╗ ███████╗███╗   ██╗██╗███████╗██████╗ 
            ██╔══██╗██╔═══██╗██╔════╝██║  ██║██╔════╝██╔════╝    ██╔══██╗██╔════╝████╗  ██║██║██╔════╝██╔══██╗
            ███████║██║   ██║██║     ███████║█████╗  █████╗      ██████╔╝█████╗  ██╔██╗ ██║██║███████╗██████╔╝
            ██╔══██║██║   ██║██║     ██╔══██║██╔══╝  ██╔══╝      ██╔═══╝ ██╔══╝  ██║╚██╗██║██║╚════██║██╔═══╝ 
            ██║  ██║╚██████╔╝╚██████╗██║  ██║███████╗███████╗    ██║     ███████╗██║ ╚████║██║███████║██║     
            ╚═╝  ╚═╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝    ╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝     
                    )" << endl;

            this_thread::sleep_for(chrono::milliseconds(500));
            system("clear");                                   
            this_thread::sleep_for(chrono::milliseconds(250)); 
        }

        system("clear");
        if (isGod) {
            // TODO
        } else {
            cout << R"(
            +--------------------------------------------------+
            |                  ACCESS DENIED                   |
            |       Your actions have been logged. Goodbye.    |
            +--------------------------------------------------+
            )" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            isLocked = true;
        }
    }
    system("clear");
}

void debug() {
    string userIn;
    cout << "Entering Debug mode. Tread carefully..." << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    system("clear");
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "ENTER DEBUG COMMAND: ";
    userIn = getUser();

    if (userIn == "UNLOCK") {
        system("clear");
        for (int i = 0; i < 5; i++) {
            loading();
            system("clear");
        }
        cout << "Override screen unlocked." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("clear");
        isLocked = false;
    } else if (userIn == "BUG") {
        system("clear");
        for (int i = 0; i < 5; i++) {
            cout << "Loading BUG:" << endl;
            loading();
            system("clear");
        }
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "MOM: WHERE ARE YOU?" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "BUG: I TOLD YOU I'D BE WORKING LATE, DIDN'T I? I THINK I LEFT A NOTE ON THE REFRIGERATOR" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "MOM: OH I'M SORRY I DIDN'T THINK TO CHECK THE REFRIGERATOR. WHY AREN'T YOU JUST TEXTING ME, TECH GUY." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "BUG: HAHA, VERY FUNNY. I WAS RUNNING LATE. I HAVE A PRETTY BIG ASSIGNMENT THAT I'VE BEEN ASSIGNED TO!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "MOM: THAT'S GREAT, HUN! I TOLD YOU THAT IF YOU JUST BUCKLED DOWN AND WORKED HARD, THAT IT WOULD ALL PAY OFF!! I'M SO PROUD OF YOU!" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "BUG: THANKS, MOM. I SHOULDN'T BE OUT TOO LATE. I'LL CALL WHEN I'M HEADING HOME." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "MOM: OKAY, HUN. BE SAFE. LOVE YOU!" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "BUG: LOVE YOU TOO, MOM." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        system("clear");
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "MOM: BUG?" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "MOM: HUNNY, WHERE ARE YOU?" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "MOM: YOU SAID YOU WOULDN'T BE LATE!" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "MOM: IF YOU DON'T ANSWER ME RIGHT NOW I'M CALLING THE POLICE!" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << endl << "RESPOND: ";
        
        cin >> userIn;
        for (int i = 0; i < 3; i++) {
            loading();
            system("clear");
        }
        cout << "MOM: BUG? IS THAT REALLY YOU?" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        userIn = getUser();

        if (userIn == "YES") {
            system("clear");
            for (int i = 0; i < 10; i++) {
                cout << "DISCREPANCY DETECTED" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                system("clear");
                this_thread::sleep_for(chrono::milliseconds(250));
            }
            cout << "CODENAME: BUG" << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "STATUS: DECEASED" << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            system("clear");
            for (int i = 0; i < 5; i++) {
                cout << "CODENAME: BUG" << endl;
                cout << "STATUS: DECEASED" << endl;
                loading();
                system("clear");
            }
            for (int i = 0; i < 5; i++) {
                cout << "UPDATING SYSTEM FILES" << endl;
                loading();
                system("clear");
            }
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "CODENAME: BUG" << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "STATUS: IN ACTION" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            for(int i = 0; i < 2; i++) {
                cout << "TERMINATING PROGRAM" << endl;
                loading();
                system("clear");
            }
            cout << "PROGRAM TERMINATED" << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            isBug = true;
        } else {
            this_thread::sleep_for(chrono::milliseconds(1000));
            system("clear");
        }
    }
}

void info() {
    system("clear");
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "+--------------------------------------+" << endl;
    cout << "|         CLASSIFIED DOCUMENT         |" << endl;
    cout << "|      SECURITY CLEARANCE: BLACK      |" << endl;
    cout << "|        FILE ID: INT-27539           |" << endl;
    cout << "+--------------------------------------+" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "LOADING FILE: theInitiative.txt" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    for (int i = 0; i < 3; i++) {
        cout << ". " << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    system("clear");

    // Main Document Header
    cout << "+--------------------------------------+" << endl;
    cout << "|      THE INITIATIVE - OVERVIEW      |" << endl;
    cout << "+--------------------------------------+" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\n> ORIGIN: UNKNOWN" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "> PRIMARY FUNCTION: [REDACTED]" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "> THREAT LEVEL: OMEGA" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "> CONTROL STATUS: LOST" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    // Start Main Information Dump
    system("clear");
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "-----------------------------" << endl;
    cout << "    THE INITIATIVE PROTOCOL" << endl;
    cout << "-----------------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nThe Initiative is **not** a conventional virus." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "It does not destroy files... " << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "It does not infect systems..." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "It **rewrites** them." << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));

    cout << "\nEvery network. Every digital structure." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "The Initiative **assimilates and reconfigures**" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "until the host civilization no longer exists." << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));

    cout << "\nIt was designed as an automated failsafe." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "A safeguard against existential threats." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "**Then it turned against us.**" << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));

    system("clear");

    cout << "-----------------------------" << endl;
    cout << "     OPERATIONAL HISTORY     " << endl;
    cout << "-----------------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n> FIRST DEPLOYMENT: [REDACTED]" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "> CIVILIZATION IMPACT: TOTAL COLLAPSE" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "> REMAINING POPULATION: [DATA CORRUPTED]" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "\nThe Initiative follows three primary protocols:" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "1. **IDENTIFY THREAT**" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "2. **NEUTRALIZE INFRASTRUCTURE**" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "3. **ERASE EXISTENCE**" << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));

    system("clear");

    cout << "-----------------------------" << endl;
    cout << "       FINAL WARNING         " << endl;
    cout << "-----------------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n> INITIATIVE ACTIVATION CODE: [SECURED]" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "> LAST LOGGED OVERRIDE ATTEMPT: FAILED" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "> INITIATIVE STATUS: ACTIVE" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "\nIf you are reading this, you have two choices." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "Run." << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << "Or **fight.**" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    system("clear");

    cout << "+--------------------------------------+" << endl;
    cout << "|     END OF CLASSIFIED FILE           |" << endl;
    cout << "+--------------------------------------+" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    system("clear");

}

void emergencyBackup() {
    system("clear");
    for (int i = 0; i < 5; i++) {
        cout << "EMERGENCY BACKUP AUTHORIZED. PLEASE STANDBY." << endl;
        loading();
        system("clear");
    }
    cout << "EMERGENCY BACKUP AUTHORIZED. PLEASE STANDBY." << endl;
    cout << "CRITICAL FAILURE" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "LOG UPDATED" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    system("clear");
    loopCounter += 1;
}

void systemLogs() {
    string userIn;

    system("clear");
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "ERROR: 0X0002231" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    system("clear");
    for (int i = 0; i < 5; i++) {
        cout << "ERROR: 0X0002231" << endl;
        cout << "DATA CORRUPTION DETECTED" << endl;
        loading();
        system("clear");
    }
    cout << "ERROR: 0X0002231" << endl;
    cout << "DATA CORRUPTION DETECTED" << endl;
    cout << "ATTEMPTING TO REPAIR INDEX" << endl;
    loading();
    system("clear");
    for(int i = 0; i < 3; i++) {
        cout << "ERROR: 0X0002231" << endl;
        cout << "DATA CORRUPTION DETECTED" << endl;
        cout << "ATTEMPTING TO REPAIR INDEX" << endl;
        cout << "STANDBY" << endl;
        system("clear");
    }
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "PARTIAL DATA RECOVERY SUCCESSFUL" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    system("clear");
    for(int i = 0; i < 5; i++) {
        loading();
        system("clear");
    }

    cout << "+-------------- DATA LOG --------------+" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "| 08/24/2022: MISSION CRITICAL EVENT   |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|                                      |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "| 08/24/2022: MISSION CRITICAL EVENT   |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|                                      |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|09/xx/xxxx: CORRUPT INDEX             |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|                                      |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|09/xx/xxxx: CORRUPT INDEX             |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|                                      |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|11/21/2024: MISSION LAUNCH AUTHORIZED |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|                                      |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|01/29/2025: MISSION CRITICAL EVENT    |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|                                      |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|01/29/2025: MISSION CRITICAL EVENT    |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 0; i < loopCounter; i++) {
        cout << "|                                      |" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "|01/29/2025: CRITICAL FAILURE          |" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "|                                      |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "|04/01/2039: ATTEMPTED BACKLOG RECOVERY|" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "+--------------------------------------+" << endl;
    system("clear");
    for (int i = 0; i < 5; i++) {
        cout << "+-------------- DATA LOG --------------+" << endl;
        cout << "| 08/24/2022: MISSION CRITICAL EVENT   |" << endl;
        cout << "|                                      |" << endl;
        cout << "| 08/24/2022: MISSION CRITICAL EVENT   |" << endl;
        cout << "|                                      |" << endl;
        cout << "|09/xx/xxxx: CORRUPT INDEX             |" << endl;
        cout << "|                                      |" << endl;
        cout << "|09/xx/xxxx: CORRUPT INDEX             |" << endl;
        cout << "|                                      |" << endl;
        cout << "|11/21/2024: MISSION LAUNCH AUTHORIZED |" << endl;
        cout << "|                                      |" << endl;
        cout << "|01/29/25: MISSION CRITICAL EVENT      |" << endl;
        cout << "|                                      |" << endl;
        cout << "|01/29/25: MISSION CRITICAL EVENT      |" << endl;
        for (int i = 0; i < loopCounter; i++) {
            cout << "|                                      |" << endl;
            cout << "|01/29/2025: CRITICAL FAILURE          |" << endl;
        }
        cout << "|                                      |" << endl;
        cout << "|04/01/2039: ATTEMPTED BACKLOG RECOVERY|" << endl;
        cout << "+--------------------------------------+" << endl;
        loading();
        system("clear");
    }
    cout << "+-------------- DATA LOG --------------+" << endl;
    cout << "| 08/24/2022: MISSION CRITICAL EVENT   |" << endl;
    cout << "|                                      |" << endl;
    cout << "| 08/24/2022: MISSION CRITICAL EVENT   |" << endl;
    cout << "|                                      |" << endl;
    cout << "|09/xx/xxxx: CORRUPT INDEX             |" << endl;
    cout << "|                                      |" << endl;
    cout << "|09/xx/xxxx: CORRUPT INDEX             |" << endl;
    cout << "|                                      |" << endl;
    cout << "|11/21/2024: MISSION LAUNCH AUTHORIZED |" << endl;
    cout << "|                                      |" << endl;
    cout << "|01/29/25: MISSION CRITICAL EVENT      |" << endl;
    cout << "|                                      |" << endl;
    cout << "|01/29/25: MISSION CRITICAL EVENT      |" << endl;
    for (int i = 0; i < loopCounter; i++) {
        cout << "|                                      |" << endl;
        cout << "|01/29/2025: CRITICAL FAILURE          |" << endl;
    }
    cout << "|                                      |" << endl;
    cout << "|04/01/2039: ATTEMPTED BACKLOG RECOVERY|" << endl;
    cout << "+--------------------------------------+" << endl;

    cout << "+-------------- DATA LOG --------------+" << endl;
    cout << "|BACKLOG RECOVERY CRITICAL FAILURE     |" << endl;
    cout << "+--------------------------------------+" << endl;

    cout << "AUTHORIZE EMERGENCY BACKUP? (Y/N): ";
    cin >> userIn;

    if (userIn == "Y") {
        emergencyBackup();
    } else if (userIn == "N") {
        cout << "EMERGENCY BACKUP DECLINED. HAVE A NICE DAY" << endl;
    } else {
        cout << "IMPROPER INPUT: TERMINATING PROTOCOL. HAVE A NICE DAY." << endl;
    }
}

void bug() {
    cout << "ERROR: ACCESS VIOLATION DETECTED..." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 0; i < 5; i++) {
        cout << "\r##############" << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
        cout << "\r              " << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    system("clear");

    cout << R"(
      ____    _    _   ____  
     | __ )  | |  | | |  __)
     |  _ \  | |  | | |    _
     | |_) | | |__| | |  _| |
     |____/   \____/  |____/ 

    Welcome to the BUG System.
    Access granted to hidden operations.
    )" << endl;
    cout << "Accessing hidden menu...\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Establishing secure connection...\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Connection established.\n\n";
    cout << "+-------------- HIDDEN MENU --------------+" << endl;
    cout << "| 1. Override The Initiative              |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "| 2. View System Logs                     |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "| 3. Activate Debug Mode                  |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "| 4. More Info...                         |" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "| 5. Exit                                 |" << endl;
    cout << "+-----------------------------------------+" << endl;

    int choice;
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            override();
            break;
        case 2:
            systemLogs();
            break;
        case 3:
            debug();
            break;
        case 4:
            info();
            break;
        case 5:
            cout << "Terminating protocol. Have a good day." << endl;
            system("clear");
            break;
        default:
            cout << "Invalid choice. Goodbye." << endl;
            system("clear");
    }
}

void bugMode() {
    int userIn;
    string response;
    string secureKey;
    system("clear");
    for (int i = 0; i < 5; i++) {
        cout << "LOGGING IN AS USER, CODENAME: BUG" << endl;
        loading();
        system("clear");
    }
    cout << "WELCOME USER, CODENAME: BUG" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "PLEASE ENTER YOUR PERSONAL IDENTIFICATION NUMBER: ";
    cin >> userIn;

    if (userIn == bugPin) {
        system("clear");
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "+----------------------------+" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "| BUG: LEVEL 72 PROGRAMMER   |" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "| CLEARENCE: MAX             |" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "| STATUS: IN ACTION          |" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "+----------------------------+" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        system("clear");
        for (int i = 0; i < 5; i++) {
            cout << "+----------------------------+" << endl;
            cout << "| BUG: LEVEL 72 PROGRAMMER   |" << endl;
            cout << "| CLEARENCE: MAX             |" << endl;
            cout << "| STATUS: IN ACTION          |" << endl;
            cout << "+----------------------------+" << endl;
            cout << "WELCOME HOME, BUG" << endl;
            loading();
            system("clear");
        }
        cout << "+----------------------------+" << endl;
        cout << "| BUG: LEVEL 72 PROGRAMMER   |" << endl;
        cout << "| CLEARENCE: MAX             |" << endl;
        cout << "| STATUS: IN ACTION          |" << endl;
        cout << "+----------------------------+" << endl;
        cout << "WELCOME HOME, BUG" << endl;
        cout << "Hello. My name is Bug. I am a tech guy. I wrote the initiative. I didn't know what it was at the time. By the time I realized just how dangerous this was, it was too late." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "I decided to implement a falesafe, like Jaylen Urso did for the Death Star in Star Wars. I had to hide it, of course, behind hidden menus and firewalls. You have successfully " << endl;
        cout << "Discovered the final of these menus." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "I must congratulate you for this achievement. You are, truly, a tech guy..." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "Or tech girl, I guess." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "That's hot." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "If you are a tech girl, and if I'm still alive by the time you're reading this, I'd love to get to know you a little better." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "My Mom makes a mean casserole." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "Anyway. I wrote into the source code several logic pathways that could potentially lead someone, such as yourself, here:" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "And where is here? Well... It's the end of the line..." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "I couldn't just give you the secure access code. There would be no way to do that without trigerring certain systems..." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "But I can give you access to manipulate the .txt file and change the secure access code..." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "I have to warn you, though. The people I work for will notice if the initiative were to go offline, pretty much immediately, and they will not hesitate to take action against you..." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "That being said, when you deactivate my program, be ready to run or fight, because a fight will be coming..." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "I truly hope I'm still alive to see you guys through, though I suspect that if you're reading this, that probably means that I'm not..." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "In a moment, you'll be prompted to enter a secure key. I've predicted a number of places where you could potentially be when you crack the code, and I've taken the liberty " << endl;
        cout << "Of stashing that code in all of these places." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "Look around for the code, and when you are prompted, enter it EXACTLY. This is very important. The system will notice any discrepancies and will shut this menu down immediately " << endl;
        cout << "In order to protect you from further repercussions." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "After you have the secure access code, you'll be able to rerun the program and terminate the initiative." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "After that, it's up to you to survive. But rest assured: If you die, you will die having saved the world from an unimaginable terror." << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "Good luck" << endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        cout << "Get ready" << endl;
        for (int i = 3; i > 0; i--) {
            cout << i << " " << flush;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        system("clear");
        for (int i = 0; i < 5; i++) {
            loading();
            system("clear");
        }
        cout << "ENTER SECURE KEY: ";
        cin >> secureKey;
        if (secureKey == "ILMMSMIWDFH") {
            system("clear");
            for (int i = 0; i < 10; i++) {
                loading();
                system("clear");
            }
            cout << "You are about to reset the Secure Access Code. Would you like to continue? (y/n): ";
            do {
                cin >> response;
            }while (response != "y" && response != "n");
            if (response == "y") {
                cout << "Please enter new 5 digit numeric Secure Access Code: ";
                cin >> userIn;
                secureAccessCode = userIn;
            } else if (response == "n") {
                cout << "Secure access code not changed. Have a good day." << endl;
            }
        } else {
            cout << "System terminated. Goodbye." << endl;
        }
    } else {
        cout << "System terminated. Goodbye." << endl;
    }
}

int main() {
    // Declare variables
    string userIn;
    input userChoice;
    int userCode;
    string label;
    const string checkLaunch("launch.txt");

    // Check data base
    ifstream inFile(checkLaunch);
    if (inFile.is_open()) {
        while(inFile >> label){
            if (label == "isLaunched:") {
                inFile >> isLaunched;
            } else if (label == "isLocked:") {
                inFile >> isLocked;
            } else if (label == "isBug:") {
                inFile >> isBug;
            } else if (label == "secureAccessCode:") {
                inFile >> secureAccessCode;
            } else if (label == "bugPin:") {
                inFile >> bugPin;
            } else if (label == "loopCounter:") {
                inFile >> loopCounter;
            }
        }
        inFile.close();
    } else {
        // Default value if file does not exist
        isLaunched = false;
        isLocked = false;
        isGod = false;
        isBug = false;
        secureAccessCode = 00000;
    }

    // Prompt user input
    cout << "+--------------- Binary User Gateway --------------+" << endl;
    cout << "|                                                  |" << endl;
    cout << "| Property of REDACTED REDACTED REDACTED Authority |" << endl;
    cout << "|                                                  |" << endl;
    cout << "+--------------------------------------------------+" << endl;
    cout << "Hello. Would you like to launch The Initiative?" << endl;
    userIn = getUser();
    userChoice = enumUserChoice(userIn);

    // Check case
    switch(userChoice) {
        case BUG:
            if (isBug) {
                bugMode();
            } else {
                bug();
            }
            break;
        case YES:
            if (isLaunched) {
                cout << "The Initiative is already launched. Have a nice day." << endl;
            } else {
                cout << "The Initiative has been launched. Have a nice day." << endl;
                isLaunched = true;
            }
            break;
        case NO:
            if (isLaunched) {
                cout << "The Initiative is already launched. Would you like to abort?" << endl;
                userIn = getUser();
                if (userIn == "YES") {
                    cout << "Please confirm: ";
                    userIn = getUser();
                    if (userIn == "YES") {
                        cout << "Please enter secure access code: ";
                        userCode = getCode();
                        if (userCode == secureAccessCode) {
                            cout << "The Initiative has been aborted, just as you should have been. Have a nice day." << endl;
                            isLaunched = false;
                        } else {
                            cout << "Access denied." << endl;
                        }
                    } else {
                        cout << "Confirmation denied. Have a nice day." << endl;
                    }
                } else {
                    cout << "Have a nice day." << endl;
                }
            } else {
                cout << "Have a nice day." << endl;
            }
            break;
        default:
            break;
    }

/*    if (userIn == "BUG") {
        if (isBug) {
            bugMode();
        } else {
            bug();
        }
    } else {
        if (isLaunched) { // If launched
            if (userIn == "YES") { // If YES
                cout << "The Initiative is already launched. Have a nice day." << endl;
            } else if (userIn == "NO") { // If NO
                cout << "The Initiative is already launched. Would you like to abort?" << endl;
                userIn = getUser();
                if (userIn == "YES") { // If abort
                    cout << "Please confirm: ";
                    userIn = getUser();
                    if (userIn == "YES") { // If confirm abort
                        cout << "Please enter secure access code: ";
                        userCode = getCode();
                        if (userCode == secureAccessCode) { // If is code
                            isLaunched = false;
                            cout << "The Initiative has been aborted, just as you should have been. Have a nice day." << endl;
                        } else { // If not code
                            cout << "Access denied." << endl;
                        }
                    } else { // If deny confirmation
                        cout << "Confirmation denied. Have a nice day." << endl;
                    }
                } else { // If deny abort
                    cout << "Have a nice day." << endl;
                }
            }
        } else { // If not launched
            if (userIn == "YES") { // If YES
                isLaunched = true;
                cout << "The Initiative has been launched. Have a nice day." << endl;
            } else if (userIn == "NO") { // If NO
                cout << "Have a nice day." << endl;
            }
        }
    }
    */

    // Close data base
    ofstream outFile(checkLaunch);
    if (outFile.is_open()) {
        outFile << "isLaunched: " << isLaunched << endl;
        outFile << "isLocked: " << isLocked << endl;
        outFile << "isBug: " << isBug << endl;
        outFile << "secureAccessCode: " << secureAccessCode << endl;
        outFile << "bugPin: " << bugPin << endl;
        outFile << "loopCounter: " << loopCounter << endl;
        outFile.close();
    } else {
        cerr << "Error: Unable to save data to file." << endl;
    }

    return 0;
}