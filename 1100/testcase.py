import random

def generate_test_cases():
    t = 5  # Fixed number of test cases
    test_cases = []
    outputs = []
    
    for _ in range(t):
        n = random.randint(1, 5)  # Variable size of array (1 ≤ n ≤ 5)
        majority_element = random.randint(0, 999)  # Random majority element

        # Ensure majority element appears more than ⌊n/2⌋ times
        majority_count = (n // 2) + 1  
        other_count = n - majority_count  

        # Create array with the majority element
        arr = [majority_element] * majority_count  

        # Fill remaining spots with random values (ensuring they don't outnumber the majority element)
        while other_count > 0:
            num = random.randint(0, 999)
            if num != majority_element:  
                arr.append(num)
                other_count -= 1
        
        random.shuffle(arr)  # Shuffle to randomize order
        test_cases.append((n, arr))
        outputs.append(majority_element)

    return t, test_cases, outputs

# Generate test cases
t, test_cases, outputs = generate_test_cases()

# Print the test cases in the required format
print(t)
for n, arr in test_cases:
    print(n)  # Print the variable n
    print(" ".join(map(str, arr)))  # Print array

print("\nExpected Output:")
for output in outputs:
    print(output)  # Print majority element
