#include <aurora/Aurora.h>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

struct TriviaQuestion {
  std::string question;
  std::vector<std::string> answers;
};

void setAuroraConfiguration() {
  if(!getenv("APP_TOKEN")){
    std::cerr << "ERROR: No \"APP_TOKEN\" environment variable set" << std::endl;
    exit(1);
  } else {
    aurora::config.appToken = getenv("APP_TOKEN");
  }
  if(!getenv("APP_ID")) {
    std::cerr << "ERROR: No \"APP_ID\" environment variable set"<< std::endl;
    exit(1);
  } else {
    aurora::config.appID = getenv("APP_ID");
  }

  //device ID is optional, if not set, set as empty string
  if(!getenv("DEVICE_ID")) {
    aurora::config.deviceID = "";
  } else {
    aurora::config.deviceID = getenv("DEVICE_ID");
  }
}

// returns true if answer is correct
bool processAnswer(const std::vector<std::string> &possibleAnswers) {
  aurora::ListenParams params;
  params.length = 3.0;
  params.silenceLen = 0.0;

  aurora::Text answerText = aurora::listenAndTranscribe(params);

  std::cout << "[HUMAN] " << answerText.getText() << std::endl;

  std::cout << "Correct Answers:" << std::endl;
  for (const std::string &answer : possibleAnswers) {
    std::cout << "  " << answer << std::endl;
  }

  for (const std::string &answer : possibleAnswers) {
    if (answerText == answer) {
      return true;
    }
  }

  return false;
}

int main(int argc, char **argv) {
  setAuroraConfiguration();

  aurora::Speech correctSpeech = aurora::Text("correct").speech();
  aurora::Speech incorrectSpeech = aurora::Text("incorrect").speech();

  int score = 0;

  std::vector<TriviaQuestion> questions = {
    {"What is the capital of california", {"Sacramento"}},
    {"From which country did the Beatles originate", {"England", "United Kingdom", "Britain", "UK"}},
    {"What song is Rebecca Black most famous for", {"Friday"}},
    {"What country has paris as its capital", {"France"}},
    {"Where is the empire state building located", {"New York"}}
  };

  for (TriviaQuestion &q : questions) {
    std::cout << "[COMPUTER] " << q.question << "?" << std::endl;

    aurora::Text(q.question).speech().getAudio().play();

    if (processAnswer(q.answers)) {
      std::cout << "[COMPUTER] Correct!" << std::endl;
      score++;
      correctSpeech.getAudio().play();
    }
    else {
      std::cout << "[COMPUTER] Incorrect!" << std::endl;
      incorrectSpeech.getAudio().play();
    }
    
    std::cout << std::endl;
  }

  std::vector<std::string> scoreMessages = {
    "You have a final score of zero. Are you even trying?",
    "You have a final score of one. At least you got the one.",
    "You have a final score of two. Almost half correct.",
    "You have a final score of three. A little over half correct.",
    "You have a final score of four. Almost perfect.",
    "You have a perfect score of five. Congratulations!"
  };

  std::cout << "[COMPUTER] " << scoreMessages[score] << std::endl;
  aurora::Text(scoreMessages[score]).speech().getAudio().play();
}
