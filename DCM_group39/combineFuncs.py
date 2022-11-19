def combine_funcs(*funcs):
    def combined_func(*arg1, **arg2):
        for f in funcs:
            f(*arg1, **arg2)
    return combined_func

def roundToNearest(input, toNearest=5):
    return toNearest * round(input/toNearest)