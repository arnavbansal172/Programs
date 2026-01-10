class Risk:
    def __init__(self, name, impact, likelihood):
        self.name = name
        self.impact = impact
        self.likelihood = likelihood

    def calculate_risk_score(self):
        return self.impact * self.likelihood

    def evaluate_risk(self):
        risk_score = self.calculate_risk_score()

        if risk_score < 10:
            return "Low"
        elif 10 <= risk_score < 20:
            return "Medium"
        else:
            return "High"

# Example
if __name__ == "__main__":
    
    example_risk = Risk("Data Breach", 4, 5)

    print(f"Risk: {example_risk.name}")
    print(f"Impact: {example_risk.impact}, Likelihood: {example_risk.likelihood}")
    print(f"Risk Level: {example_risk.evaluate_risk()}")
