#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

char *b64_enc_str(const unsigned char *in, int in_len)
{
	BIO *b64;
	BIO *bmem;
	BUF_MEM *bptr;
	char *out;

    b64 = BIO_new(BIO_f_base64());
    if (NULL == b64)
        return NULL;
    bmem = BIO_new(BIO_s_mem());
    if (NULL == bmem)
        return NULL;
	b64 = BIO_push(b64, bmem);
    if (BIO_write(b64, in, in_len) <= 0)
        return NULL;
	BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);
    BIO_set_close(b64, BIO_NOCLOSE);

	out = (char*)malloc(bptr->length);
	if (NULL == out)
		return NULL;
	memcpy(out, bptr->data, bptr->length - 1);
	out[bptr->length-1] = '\0';

	BIO_free_all(b64);
	return out;
}

int b64_enc_fp(const char *filename, const unsigned char *in, int in_len)
{
	BIO *b64;
	BIO *bmem;

	b64 = BIO_new(BIO_f_base64());
	bmem = BIO_new_file(filename, "w");
	b64 = BIO_push(b64, bmem);
	BIO_write(b64, in, in_len);
	BIO_flush(b64);

    BIO_free_all(b64);
    
    return 0;
}

char *b64_dec_str(const unsigned char *in, int in_len)
{
	BIO *b64;
	BIO *bmem;
	char *out;
	out = (char*)malloc(in_len);
	memset(out, 0, in_len);

	b64 = BIO_new(BIO_f_base64());
	bmem = BIO_new_mem_buf((void*)in, in_len);
	// key point flag setting to decode
	BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
	bmem = BIO_push(b64, bmem);
	int ret = BIO_read(bmem, out, in_len);
	if (ret <= 0)
	{
		BIO_free_all(bmem);
		return NULL;
	}
	BIO_free_all(bmem);
	return out;
}

int main()
{
	char *str = "hello edony";
	char *b64_str = b64_enc_str((unsigned char*)str, strlen(str));
	printf("encoded base64 string: (%s : %lu)\n", b64_str, strlen(b64_str));
	char *ub64_str = b64_dec_str((unsigned char*)b64_str, strlen(b64_str));
	printf("%s\n", ub64_str);
	if(0 == strcmp(str, ub64_str))
		printf("decode success\n");
    b64_enc_fp("test_file.buff", (unsigned char*)str, strlen(str));
    
    return 0;
}