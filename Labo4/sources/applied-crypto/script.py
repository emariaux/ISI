#!/usr/bin/env python3

from isi_labo4_functions import *

# KEYS
print("Generate private keys for Alice, Bob and Charlie")
# TODO : Generate the private keys for Alice, Bob and Charlie
privkey_alice = gen_privkey()
privkey_bob = gen_privkey()
privkey_charlie = gen_privkey()
save_privkey("./output/alice/privkey.pem", privkey_alice)
save_privkey("./output/bob/privkey.pem", privkey_bob)
save_privkey("./output/charlie/privkey.pem", privkey_charlie)

############################################
# CERTIFICATES

############################################
# Root certificate
# Remark : Use 'Alice', 'Bob' and 'Charlie' as COMMON_NAME for their identity

# Charlie creates a self-signed certificate to be used for his root CA
print("Charlie creates a root certificate for his own CA")
# Certificate must be valid for 10 years
# TODO : Create a self-signed certificate for Charlie
cert_charlie_identity = create_identity("Charlie")
cert_charlie_duration = get_duration(3650)
cert_charlie = create_root_certificate(privkey_charlie, cert_charlie_duration, cert_charlie_identity)
save_cert("./output/charlie/cert.pem", cert_charlie)


############################################
# CSR
# Alice and Bob create a certificate request to be submitted to Charlie's CA
print("Alice and Bob create their Certificate Signing Request")
# Alice
# TODO : Create a CSR for Alice
csr_alice_indentity = create_identity("Alice")
csr_alice = create_server_csr(privkey_alice, csr_alice_indentity)
save_csr("./output/alice/cert.csr", csr_alice)

# Bob
# TODO : Create a CSR for Bob
csr_bob_indentity = create_identity("Bob")
csr_bob = create_server_csr(privkey_bob, csr_bob_indentity)
save_csr("./output/bob/cert.csr", csr_bob)


############################################
# Sign CSRs
# Charlie's CA sign the CSRs to issue certificates
print("Charlie signs the CSR")
# Certificates must be valid for 3 months, each

# TODO : Sign the CSRs or Alice and Bob with the certificate of Charlie as root
# TODO : they must be valid for 3 months

cert_alice_duration = get_duration(90)
cert_bob_duration = get_duration(90)

cert_alice = sign_csr(csr_alice, cert_alice_duration, cert_charlie, privkey_charlie)
cert_bob = sign_csr(csr_bob, cert_bob_duration, cert_charlie, privkey_charlie)

save_cert("./output/alice/cert.pem", cert_alice)
save_cert("./output/bob/cert.pem", cert_bob)

# Verify certificates
print("We stop there in case a certificate is not valid")
assert verify_root_cert(cert_charlie), "Charlie's certificate is invalid !"
assert verify_cert(cert_charlie, cert_alice, "Alice"), "Alice's certificate is invalid !"
assert verify_cert(cert_charlie, cert_bob, "Bob"), "Bob's certificate is invalid !"

############################################
# Sign data

# Alice writes a text message and signs it with her private key
print("Alice signs a text message with her private key")
# TODO : Sign a message with Alice's private key
# msg = ...
# signature = ...

msg = "test alice".encode('utf-8')
signature = sign(privkey_alice, msg)

# Verify Alice's signature (using assert)
assert verify_cert(cert_charlie, cert_alice, "Alice"), "Alice's certificate is invalid !"
assert verify_signature(cert_alice, signature, msg), "Signature is invalid !"

save_signature("./output/alice/signature.txt", msg, signature)


############################################
# Send encrypted data
# Alice writes a text message and encrypts it so that only Bob can read it
print("Alice writes an encrypted message for Bob")

# TODO : Encrypt a message with a symmetric key
msg = "alice test message to bob".encode('utf-8')
key = gen_sym_key()
cipher = encrypt(key, msg)
# TODO : Wrap the key with Bob's public key
pubkey_bob = get_pubkey(privkey_bob)
boxed_key = wrap_key(pubkey_bob, key) 

save_hybrid_encryption("./output/bob/hybrid_encryption.txt", boxed_key, cipher)

# Here, Alice sends boxed_key and cipher to Bob through the network

# Bob's side
print("Bob decrypts the data")
# TODO : Unwrap the key
unboxed_key = unwrap_key(privkey_bob, boxed_key)
assert unboxed_key == key, "Unwrapping of key failed"

# TODO : Decrypt the message
plain_msg = decrypt(key, cipher) 
assert plain_msg == msg, "Decryption of message failed"
