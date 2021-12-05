from time import sleep
from selenium import webdriver
from selenium.common.exceptions import UnexpectedTagNameException, TimeoutException, NoSuchElementException
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
from JsonStorage import *


def my_open(conf):
    if conf.navigator == "chrome":
        driver = webdriver.Chrome(ChromeDriverManager().install())
        driver.get(conf.url)
    else:
        driver = webdriver.Firefox()
        driver.get(conf.url)
    sleep(10)
    my_search(conf, driver)
    parse(conf, driver)


def my_search(conf, driver):
    search_bar = driver.find_element_by_name(conf.element[0])
    search_bar.send_keys(conf.key_word)
    search_bar.send_keys(Keys.ENTER)


def parse(conf, driver):
    is_last_page = False
    for n in range(0, conf.page_nb):
        tests = driver.find_element_by_xpath(conf.element[1])
        offers = tests.find_elements_by_tag_name(conf.element[2])
        for i in range(1, conf.nb):
            try:
                if i in range(1, (len(offers) - 18)):
                    titles = offers[i].find_elements_by_xpath(conf.element[3])
                    print("Titre : ", titles[i].text)
                    image = offers[i].find_elements_by_xpath(conf.element[4])
                    print("Image : ", image[i].get_attribute(conf.element[5]))
                    price = offers[i].find_elements_by_xpath(conf.element[6])
                    print("Titre : ", price[i].text)
                    print("")
                    fil_data(str(titles[i].text), str(image[i].get_attribute(conf.element[5])), str(price[i].text))
            except (UnexpectedTagNameException, TimeoutException, NoSuchElementException):
                pass
        next_page = driver.find_element_by_css_selector(conf.element[7])
        is_last_page = next_page.get_attribute(conf.element[8])
        next_page.click()
        sleep(10)
    print(get_data())
