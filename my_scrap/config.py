from dataclasses import dataclass


@dataclass
class Config:
    def __init__(self, url, navigator, key_word, element):
        self.url = url
        self.key_word = key_word
        self.navigator = navigator
        self.element = element
