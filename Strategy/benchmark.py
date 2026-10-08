"""
Test Bench
"""
from runner import Runner

if __name__ == "__main__":
    rn = Runner()
    rn.run(start=10_000, end=50_000, growth_factor=0.1 ,save_path=False)
    rn.visualize(show=True, save_path="result.png")

