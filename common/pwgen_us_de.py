#!/usr/bin/env python3

import secrets

consonants_u = "QWRTPSDFGHJKLZXCVBNM"
consonants = "qwrtpsdfghjklzxcvbnm"
vocals_U = "EUIOA"
vocals = "euioa"
numbers = "1234567890"
specials = "!.,$"

if __name__ == "__main__":
    pw = secrets.choice(consonants_u) + \
        secrets.choice(vocals) + \
        secrets.choice(consonants) + \
        secrets.choice(vocals) + \
        secrets.choice(consonants) + \
        secrets.choice(numbers) + \
        secrets.choice(numbers) + \
        secrets.choice(specials)
    print(pw)
