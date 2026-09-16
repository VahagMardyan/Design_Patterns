class HTTPRequest:
    def __init__(self, builder : "HTTPRequestBuilder") -> None:
        self.__url = builder.url
        self.__method = builder.method
        self.__headers = builder.headers
        self.__body = builder.body
        self.__timeoutMs = 3000

    @property
    def url(self) -> str:
        return self.__url

    @property
    def method(self) -> str:
        return self.__method

    @property
    def headers(self) -> dict:
        return self.__headers.copy()

    @property
    def body(self) -> any:
        return self.__body

    @property
    def timeout_ms(self) -> int:
        return self.__timeoutMs

    def __str__(self) -> str:
        return (
            f"URL: {self.__url}\n"
            f"Method: {self.__method}\n"
            f"Headers: {self.__headers}\n"
            f"Body: {self.__body}\n"
            f"Timeout (ms): {self.__timeoutMs}"
        )

class HTTPRequestBuilder:
    def __init__(self, url : str) -> None:
        self.url = url
        self.method = "GET"
        self.headers = {}
        self.body = None

    def change_method(self, method : str) -> "HTTPRequestBuilder":
        self.method = method
        return self

    def add_headers(self, headers: dict) -> 'HTTPRequestBuilder':
        self.headers.update(headers)
        return self

    def add_body(self, body : any) -> "HTTPRequestBuilder":
        self.body = body
        return self

    def build(self) -> HTTPRequest:
        if self.method in ("DELETE", "GET") and self.body is not None:
            raise ValueError(f"{self.method} request cannot contain a body")
        
        if not self.url or not self.url.strip():
            raise ValueError("URL is empty")
        return HTTPRequest(self)

request = (
    HTTPRequestBuilder(url="https://api_example.com")
    .change_method("POST")
    .add_headers({"Content-Type": "application/json"})
    .add_body({"User" : "user1204", "Role": "Developer"}).build()
    )
print(request)
print("-"*20)
print(request.url) # https://api_example.com

# request.url = "https://example.com" # Will raise an AttributeError