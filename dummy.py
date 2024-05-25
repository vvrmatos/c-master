import requests
from bs4 import BeautifulSoup
from tkinter import Tk, Label, Button

class WebScraperApp:
    def __init__(self):
        self.listed_products = []
        self.PRODUCT_URL_LIST = [
            "https://example.com/product1",
            "https://example.com/product2",
            "https://example.com/product3"
        ]
        self.window = None
        self.label = None
    
    def fetch_price_data(self):
        self.listed_products = []
        for i, url in enumerate(self.PRODUCT_URL_LIST, start=1):
            response = requests.get(url)
            soup = BeautifulSoup(response.content, "html.parser")
            product_name_elem = soup.find_all("h1")
            product_price_elem = soup.find(class_="product-price")
            
            if product_name_elem and product_price_elem:
                product_name = product_name_elem[0].text.strip()
                product_price = product_price_elem.text.strip().split("€")[1]
                data = f"{i}. {product_name} - {product_price}"
                self.listed_products.append(data)
            else:
                self.listed_products.append(f"Product information not found for URL: {url}")
        
        # Update label text with fetched data
        self.update_label_text()
                
    def make_gui(self):
        self.window = Tk()
        self.window.config(width=600, height=400, background="#68BB59")
        self.window.title("Web Scraper App")
        self.window.resizable(width=False, height=False)
        
        sync_button = Button(self.window, text="SYNC", command=self.fetch_price_data)
        sync_button.place(x=500, y=350)
        
        self.label = Label(self.window, width=60, height=20, text="", justify="left", anchor="nw")
        self.label.place(x=20, y=20)
        
        self.window.mainloop()
    
    def update_label_text(self):
        data = "\n".join(self.listed_products)
        self.label.config(text=data)
        
if __name__ == "__main__":
    app = WebScraperApp()
    app.make_gui()
