import numpy as np
import pandas as pd

rg = np.random.default_rng()

def generate_data(n_features, n_values):
    features = rg.random((n_features, n_values))
    weights = rg.random((1, n_values))[0]
    targets = np.random.choice([0,1], n_features)

    print("generated features:")
    print(features)
    print("")
    print("generated weights:")
    print(weights)
    print("")
    print("generated targets:")
    print(targets)

    data = pd.DataFrame(features, columns=["x0", "x1", "x2"])
    data["targets"] = targets

    print("")
    print("full dataframe:")
    print(data)
    print("")

    return data, weights
