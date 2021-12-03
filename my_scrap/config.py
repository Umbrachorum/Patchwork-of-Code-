from dataclasses import dataclass


@dataclass
class Config:
    def __init__(self, url, navigator, key_word, element, nb_elem, page_nb):
        self.url = url
        self.key_word = key_word
        self.navigator = navigator
        self.element = element
        self.nb = nb_elem
        self.page_nb = page_nb
