#include <aurora/Aurora.h>
#include <string>
#include <vector>

//Probably a better way than using a callback per question
bool CallbackQ1(aurora::Text &text){
  aurora::Interpret r1 = text.interpret();
  std::string location = i.entities["location"];
  std::vector<std::string> validWords = {"sacramento"};
  int tScore = score;
  for (std::string &word : validWords) {
    if (location == word) {
        tScore++;
      break;
     }
    }
  if(tScore != score) {
    Cresp.audio.play();
    score++;
    }
  else
      Iresp.play();
  //continue listening
  return true;
}

bool CallbackQ2(aurora::Text &text){
  aurora::Interpret r1 = text.interpret();
  std::string location = i.entities["location"];
  std::vector<std::string> validWords = {"england", "united kingdom", "britain", "uk"};
  int tScore = score;
  for (std::string &word : validWords) {
    if (location == word) {
        tScore++;
      break;
     }
    }
  if(tScore != score) {
    Cresp.audio.play();
    score++;
    }
  else
    Iresp.play();
  // continue listening
  return true;
}

bool CallbackQ3(aurora::Text &text){
  aurora::Interpret r1 = text.interpret();
  std::string location = i.entities["song"];
  std::vector<std::string> validWords = {"friday"};
  int tScore = score;
  for (std::string &word : validWords) {
    if (location == word) {
        tScore++;
      break;
     }
    }
  if(tScore != score) {
    Cresp.audio.play();
    score++;
    }
  else
    Iresp.play();
  // continue listening
  return true;
}

bool CallbackQ4(aurora::Text &text){
  aurora::Interpret r1 = text.interpret();
  std::string location = i.entities["location"];
  std::vector<std::string> validWords = {"france"};
  int tScore = score;
  for (std::string &word : validWords) {
    if (location == word) {
        tScore++;
      break;
     }
    }
  if(tScore != score) {
    Cresp.audio.play();
    score++;
    }
  else
    Iresp.play();
  // continue listening
  return true;
}  

bool CallbackQ5(aurora::Text &text){
  aurora::Interpret r1 = text.interpret();
  std::string location = i.entities["location"];
  std::vector<std::string> validWords = {"new york"};
  int tScore = score;
  for (std::string &word : validWords) {
    if (location == word) {
        tScore++;
      break;
     }
    }
  if(tScore != score) {
    Cresp.audio.play();
    score++;
    }
  else
    Iresp.play();
  // continue listening
  return true;
}

int score = 0;

int main(int argc, char **argv) {
  aurora::config.appID = "YOUR_APP_ID";
  aurora::config.appToken = "YOUR_APP_TOKEN";
  aurora::config.deviceID = "YOUR_DEVICE_ID";
  //create default listen parameters
  aurora::ListenParams params;
  
  //Shows using Text to Speech
  aurora::Speech Q1 = aurora::Text("What is the capital of California?").speech();
  aurora::Speech Q2 = aurora::Text("From which country did the Beatles originate?").speech();
  aurora::Speech Q3 = aurora::Text("What song is Rebecca Black most famous for?").speech();
  aurora::Speech Q4 = aurora::Text("What country has Paris as its capital?").speech();
  aurora::Speech Q5 = aurora::Text("Where is the empire state building located?").speech();
  
  aurora::Speech Cresp = aurora::Text("Correct").speech();
  aurora::Speech Iresp = aurora::Text("Incorrect").speech();

//Shows using SST and transcribe
  Q1.audio.play();
  aurora::listenAndTranscribe(params, CallbackQ1);
  Q2.audio.play();
  aurora::listenAndTranscribe(params, CallbackQ2);
  Q3.audio.play();
  aurora::listenAndTranscribe(params, CallbackQ3);
  Q3.audio.play();
  aurora::listenAndTranscribe(params, CallbackQ3);
  Q5.audio.play();
  aurora::listenAndTranscribe(params, CallbackQ5);
//Count score and give feedback
  switch(count) {
    case 0:
      aurora::Speech finalR = aurora::Text("You have a final score of zero. are you even trying?").speech();
      break;
    case 1:
      aurora::Speech finalR = aurora::Text("You have a final score of one. At least you got the one").speech();
      break;
    case 2:
      aurora::Speech finalR = aurora::Text("You have a final score of two. Almost half correct").speech();
      break;
    case 3:
      aurora::Speech finalR = aurora::Text("You have a final score of three. A little over half correct").speech();
      break;
    case 4:
      aurora::Speech finalR = aurora::Text("You have a final score of four. Almost perfect").speech();
      break;
    case 5:
      aurora::Speech finalR = aurora::Text("You have a final score of five. congratulations").speech();
      break;
    default:
      aurora::Speech finalR = aurora::Text("Something is broken").speech();
      break;
  }

  finalR.audio.play();

}

