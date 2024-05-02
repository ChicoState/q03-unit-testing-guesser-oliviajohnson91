#include "Guesser.h"
#include <string>
using std::string;
unsigned int Guesser::distance(string guess){
  int i = 0;
  unsigned int dist = 0;
  if (guess == m_secret){
    return 0;
  } 
  while(i < guess.length() && i < m_secret.length()){
    if (guess[i] != m_secret[i]){
      dist++;
    }
    i++;
  }
  if (guess.length() > i){
    dist += guess.length() - i;
    if (dist >= m_secret.length()){
      dist = m_secret.length();
    }
  } else if (m_secret.length() > i){
    dist += m_secret.length() - i;
  }
  return dist;
}

Guesser::Guesser(string secret){
  if (secret.length() <= 32){
    m_secret = secret;
    lockedOut = false;
    m_remaining = 3;
  } else {
    m_secret = secret.substr(0, 32);
    lockedOut = false;
    m_remaining = 3;
  }
}

bool Guesser::match(string guess){
  if(m_remaining == 0){
    lockedOut = true;
    return false;
  }
  if(distance(guess) == 0){
    if (lockedOut){
      m_remaining--;
      return false;
    }
    m_remaining = 3;
    return true;
  }
  if(distance(guess)> 2){
    lockedOut = true;
    m_remaining--;
    return false;
  }
  else {
    m_remaining--;
    return false;
  }
}

unsigned int Guesser::remaining(){
  return m_remaining;
}

